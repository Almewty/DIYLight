using SharpDX;
using SharpDX.Direct3D11;
using SharpDX.DXGI;
using System;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;
using Device = SharpDX.Direct3D11.Device;
using MapFlags = SharpDX.Direct3D11.MapFlags;
using Resource = SharpDX.DXGI.Resource;
using ResultCode = SharpDX.DXGI.ResultCode;

namespace RustyDevelopment.AmbiLED
{
    public class MonitorCapture
    {
        #region Private Fields

        private Device _device;
        private OutputDuplication _duplicatedOutput;
        private bool _gotFirstFrame;
        private int _height;
        private Texture2D _screenTexture;
        private Texture2DDescription _textureDesc;
        private CancellationTokenSource _tokenSource;
        private int _width;

        #endregion Private Fields

        #region Public Properties

        public Adapter1 Adapter { get; }
        public Output1 Output { get; }

        #endregion Public Properties

        #region Public Events

        public event EventHandler<PixelCollection> GotFrame;

        #endregion Public Events

        #region Public Constructors

        public MonitorCapture(Adapter1 adapter, Output1 output)
        {
            Adapter = adapter;
            Output = output;

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

        #endregion Public Methods

        #region Private Methods

        private Stopwatch stopwatch = new Stopwatch();

        private void Capture()
        {
            try
            {
                Resource screenResource;
                OutputDuplicateFrameInformation duplicateFrameInformation;

                // Try to get duplicated frame within given time
                _duplicatedOutput.AcquireNextFrame(10000, out duplicateFrameInformation, out screenResource);

                if (_gotFirstFrame)
                {
                    // copy resource into memory that can be accessed by the CPU
                    using (var screenTexture2D = screenResource.QueryInterface<Texture2D>())
                        _device.ImmediateContext.CopyResource(screenTexture2D, _screenTexture);

                    // Get the desktop capture texture
                    var mapSource = _device.ImmediateContext.MapSubresource(_screenTexture, 0, MapMode.Read, MapFlags.None);

                    stopwatch.Restart();
                    // Send captured frame
                    GotFrame?.Invoke(this, new PixelCollection(mapSource.DataPointer, _height, _width));
                    Debug.WriteLine("GotFrame: " + stopwatch.ElapsedMilliseconds);

                    // Release source and dest locks
                    _device.ImmediateContext.UnmapSubresource(_screenTexture, 0);
                }
                _gotFirstFrame = true;
                screenResource.Dispose();
                _duplicatedOutput.ReleaseFrame();
            }
            catch (SharpDXException e) when (e.ResultCode.Code == ResultCode.AccessLost.Result.Code)
            {
                Init();
            }
            catch (SharpDXException e) when (e.ResultCode.Code == ResultCode.WaitTimeout.Result.Code)
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

        private void Init()
        {
            _screenTexture?.Dispose();
            _duplicatedOutput?.Dispose();
            _device?.Dispose();

            _device = new Device(Adapter);
            _width = Output.Description.DesktopBounds.Right - Output.Description.DesktopBounds.Left;
            _height = Output.Description.DesktopBounds.Bottom - Output.Description.DesktopBounds.Top;
            _textureDesc = new Texture2DDescription
            {
                CpuAccessFlags = CpuAccessFlags.Read,
                BindFlags = BindFlags.None,
                Format = Format.B8G8R8A8_UNorm,
                Width = _width,
                Height = _height,
                OptionFlags = ResourceOptionFlags.None,
                MipLevels = 1,
                ArraySize = 1,
                SampleDescription = { Count = 1, Quality = 0 },
                Usage = ResourceUsage.Staging
            };
            _screenTexture = new Texture2D(_device, _textureDesc);
            _duplicatedOutput = Output.DuplicateOutput(_device);
            _gotFirstFrame = false;
        }

        #endregion Private Methods
    }
}