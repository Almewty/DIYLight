using System.Collections.Generic;
using System.Drawing;

namespace Arduino.Lights
{
    public class DesktopCapture
    {
        #region Private Fields

        private SharpDX.DXGI.Adapter1 adapter;
        private SharpDX.Direct3D11.Device device;
        private SharpDX.DXGI.OutputDuplication duplicatedOutput;
        private SharpDX.DXGI.Factory1 factory;
        private bool gotFirstFrame = false;
        private int height;
        private SharpDX.DXGI.Output output;
        private SharpDX.DXGI.Output1 output1;
        private int pixels;
        private SharpDX.Direct3D11.Texture2D screenTexture;
        private SharpDX.Direct3D11.Texture2DDescription textureDesc;
        private int width;

        #endregion Private Fields

        #region Public Properties

        public int Adapter { get; }
        public Dictionary<byte, Rectangle> Filter { get; }
        public Lights Lights { get; }
        public int OutputDevice { get; }

        #endregion Public Properties

        #region Public Constructors

        public DesktopCapture(Lights light, int adapter, int outputDev)
        {
            Adapter = adapter;
            OutputDevice = outputDev;
            Filter = new Dictionary<byte, Rectangle>();
            Lights = light;

            Init();
        }

        #endregion Public Constructors

        #region Public Methods

        public unsafe void Capture()
        {
            try
            {
                SharpDX.DXGI.Resource screenResource;
                SharpDX.DXGI.OutputDuplicateFrameInformation duplicateFrameInformation;

                // Try to get duplicated frame within given time
                duplicatedOutput.AcquireNextFrame(10000, out duplicateFrameInformation, out screenResource);

                if (gotFirstFrame)
                {
                    // copy resource into memory that can be accessed by the CPU
                    using (var screenTexture2D = screenResource.QueryInterface<SharpDX.Direct3D11.Texture2D>())
                        device.ImmediateContext.CopyResource(screenTexture2D, screenTexture);

                    // Get the desktop capture texture
                    var mapSource = device.ImmediateContext.MapSubresource(screenTexture, 0, SharpDX.Direct3D11.MapMode.Read, SharpDX.Direct3D11.MapFlags.None);

                    // Copy pixels from screen capture Texture to GDI bitmap
                    var sourcePtr = (byte*)mapSource.DataPointer.ToPointer();

                    foreach (var kvp in Filter)
                    {
                        long red = 0;
                        long green = 0;
                        long blue = 0;

                        var rect = kvp.Value;
                        byte index = kvp.Key;
                        for (int y = rect.Top; y < rect.Bottom; y++)
                        {
                            int offset = mapSource.RowPitch * y + rect.Left * 4;
                            for (int x = rect.Left; x < rect.Right; x++)
                            {
                                blue += sourcePtr[offset + 0];
                                green += sourcePtr[offset + 1];
                                red += sourcePtr[offset + 2];
                                offset += 4;
                            }
                        }

                        int size = rect.Width * rect.Height;

                        red /= size;
                        green /= size;
                        blue /= size;

                        Lights.QueueColor(index, (byte)red, (byte)green, (byte)blue);
                    }

                    Lights.FlushColors();

                    // Release source and dest locks
                    device.ImmediateContext.UnmapSubresource(screenTexture, 0);
                }
                gotFirstFrame = true;
                screenResource.Dispose();
                duplicatedOutput.ReleaseFrame();
            }
            catch (SharpDX.SharpDXException e) when (e.ResultCode.Code == SharpDX.DXGI.ResultCode.AccessLost.Result.Code)
            {
                Init();
            }
            catch (SharpDX.SharpDXException e) when (e.ResultCode.Code == SharpDX.DXGI.ResultCode.WaitTimeout.Result.Code)
            {
                // ignore
            }
        }

        #endregion Public Methods

        #region Private Methods

        private void Init()
        {
            screenTexture?.Dispose();
            output1?.Dispose();
            output?.Dispose();
            factory?.Dispose();
            duplicatedOutput?.Dispose();
            device?.Dispose();
            adapter?.Dispose();

            factory = new SharpDX.DXGI.Factory1();
            adapter = factory.GetAdapter1(Adapter);
            device = new SharpDX.Direct3D11.Device(adapter);
            output = adapter.GetOutput(OutputDevice);
            output1 = output.QueryInterface<SharpDX.DXGI.Output1>();
            width = output.Description.DesktopBounds.Right - output.Description.DesktopBounds.Left;
            height = output.Description.DesktopBounds.Bottom - output.Description.DesktopBounds.Top;
            pixels = width * height;
            textureDesc = new SharpDX.Direct3D11.Texture2DDescription
            {
                CpuAccessFlags = SharpDX.Direct3D11.CpuAccessFlags.Read,
                BindFlags = SharpDX.Direct3D11.BindFlags.None,
                Format = SharpDX.DXGI.Format.B8G8R8A8_UNorm,
                Width = width,
                Height = height,
                OptionFlags = SharpDX.Direct3D11.ResourceOptionFlags.None,
                MipLevels = 1,
                ArraySize = 1,
                SampleDescription = { Count = 1, Quality = 0 },
                Usage = SharpDX.Direct3D11.ResourceUsage.Staging
            };
            screenTexture = new SharpDX.Direct3D11.Texture2D(device, textureDesc);
            duplicatedOutput = output1.DuplicateOutput(device);
        }

        #endregion Private Methods
    }
}