using System;
using System.Collections.Generic;
using System.Drawing;

namespace RustyDevelopment.AmbiLED
{
    public class MonitorCapture
    {
        #region Private Fields

        private SharpDX.DXGI.Adapter1 _adapter;
        private SharpDX.Direct3D11.Device _device;
        private SharpDX.DXGI.OutputDuplication _duplicatedOutput;
        private SharpDX.DXGI.Factory1 _factory;
        private bool _gotFirstFrame;
        private int _height;
        private SharpDX.DXGI.Output _output;
        private SharpDX.DXGI.Output1 _output1;
        private SharpDX.Direct3D11.Texture2D _screenTexture;
        private SharpDX.Direct3D11.Texture2DDescription _textureDesc;
        private int _width;

        #endregion Private Fields

        #region Public Properties

        public int Adapter { get; }
        public Dictionary<byte, Rectangle> Filter { get; }
        public int OutputDevice { get; }

        #endregion Public Properties

        #region Public Events

        public event Action<byte, byte, byte, byte> ProcessColor;

        #endregion Public Events

        #region Public Constructors

        public MonitorCapture(int adapter, int outputDev)
        {
            Adapter = adapter;
            OutputDevice = outputDev;
            Filter = new Dictionary<byte, Rectangle>();

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
                _duplicatedOutput.AcquireNextFrame(10000, out duplicateFrameInformation, out screenResource);

                if (_gotFirstFrame)
                {
                    // copy resource into memory that can be accessed by the CPU
                    using (var screenTexture2D = screenResource.QueryInterface<SharpDX.Direct3D11.Texture2D>())
                        _device.ImmediateContext.CopyResource(screenTexture2D, _screenTexture);

                    // Get the desktop capture texture
                    var mapSource = _device.ImmediateContext.MapSubresource(_screenTexture, 0, SharpDX.Direct3D11.MapMode.Read, SharpDX.Direct3D11.MapFlags.None);

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

                        ProcessColor?.Invoke(index, (byte)red, (byte)green, (byte)blue);
                    }

                    // Release source and dest locks
                    _device.ImmediateContext.UnmapSubresource(_screenTexture, 0);
                }
                _gotFirstFrame = true;
                screenResource.Dispose();
                _duplicatedOutput.ReleaseFrame();
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
            _screenTexture?.Dispose();
            _output1?.Dispose();
            _output?.Dispose();
            _factory?.Dispose();
            _duplicatedOutput?.Dispose();
            _device?.Dispose();
            _adapter?.Dispose();

            _factory = new SharpDX.DXGI.Factory1();
            _adapter = _factory.GetAdapter1(Adapter);
            _device = new SharpDX.Direct3D11.Device(_adapter);
            _output = _adapter.GetOutput(OutputDevice);
            _output1 = _output.QueryInterface<SharpDX.DXGI.Output1>();
            _width = _output.Description.DesktopBounds.Right - _output.Description.DesktopBounds.Left;
            _height = _output.Description.DesktopBounds.Bottom - _output.Description.DesktopBounds.Top;
            _textureDesc = new SharpDX.Direct3D11.Texture2DDescription
            {
                CpuAccessFlags = SharpDX.Direct3D11.CpuAccessFlags.Read,
                BindFlags = SharpDX.Direct3D11.BindFlags.None,
                Format = SharpDX.DXGI.Format.B8G8R8A8_UNorm,
                Width = _width,
                Height = _height,
                OptionFlags = SharpDX.Direct3D11.ResourceOptionFlags.None,
                MipLevels = 1,
                ArraySize = 1,
                SampleDescription = { Count = 1, Quality = 0 },
                Usage = SharpDX.Direct3D11.ResourceUsage.Staging
            };
            _screenTexture = new SharpDX.Direct3D11.Texture2D(_device, _textureDesc);
            _duplicatedOutput = _output1.DuplicateOutput(_device);
            _gotFirstFrame = false;
        }

        #endregion Private Methods
    }
}