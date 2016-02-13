using System;
using System.Threading;
using System.Threading.Tasks;

namespace RustyDevelopment.AmbiLED
{
    public class MonitorCapture
    {
        #region Private Fields

        private readonly SharpDX.DXGI.Adapter1 _adapter;
        private readonly SharpDX.DXGI.Output1 _output1;
        private SharpDX.Direct3D11.Device _device;
        private SharpDX.DXGI.OutputDuplication _duplicatedOutput;
        private bool _gotFirstFrame;
        private int _height;
        private SharpDX.Direct3D11.Texture2D _screenTexture;
        private SharpDX.Direct3D11.Texture2DDescription _textureDesc;
        private CancellationTokenSource _tokenSource;
        private int _width;

        #endregion Private Fields



        #region Public Events

        public event EventHandler<PixelCollection> GotFrame;

        #endregion Public Events

        #region Public Constructors

        public MonitorCapture(SharpDX.DXGI.Adapter1 adapter, SharpDX.DXGI.Output1 output)
        {
            _adapter = adapter;
            _output1 = output;

            Init();
        }

        #endregion Public Constructors

        #region Public Methods

        public void StartCapturing()
        {
            _tokenSource?.Cancel();
            _tokenSource = new CancellationTokenSource();
            Task.Factory.StartNew(() => CaptureLoop(_tokenSource.Token), _tokenSource.Token,
                TaskCreationOptions.LongRunning, TaskScheduler.Default);
        }

        public void StopCapturing()
        {
            _tokenSource.Cancel();
        }

        private void Capture()
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

                    // Send captured frame
                    GotFrame?.Invoke(this, new PixelCollection(mapSource.DataPointer, _height, _width));

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

        private void CaptureLoop(CancellationToken cancellationToken)
        {
            while (!cancellationToken.IsCancellationRequested)
            {
                Capture();
            }
        }

        #endregion Public Methods

        #region Private Methods

        private void Init()
        {
            _screenTexture?.Dispose();
            _duplicatedOutput?.Dispose();
            _device?.Dispose();

            _device = new SharpDX.Direct3D11.Device(_adapter);
            _width = _output1.Description.DesktopBounds.Right - _output1.Description.DesktopBounds.Left;
            _height = _output1.Description.DesktopBounds.Bottom - _output1.Description.DesktopBounds.Top;
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