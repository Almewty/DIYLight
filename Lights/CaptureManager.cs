using SharpDX.DXGI;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

namespace RustyDevelopment.AmbiLED
{
    public class CaptureManager
    {
        #region Private Fields

        private readonly IList<MonitorCapture> _captures;
        private readonly Factory1 _factory;

        #endregion Private Fields

        #region Public Properties

        public IReadOnlyList<MonitorCapture> Captures => _captures as IReadOnlyList<MonitorCapture>;

        public IEnumerable<GraphicsAdapter> GraphicsAdapters =>
                    _factory.Adapters1.Select(a => new GraphicsAdapter(a));

        #endregion Public Properties

        #region Public Constructors

        public CaptureManager()
        {
            _captures = new List<MonitorCapture>();
            _factory = new Factory1();
        }

        #endregion Public Constructors

        #region Public Methods

        public void AddCapture(OutputDevice device)
        {
            var capture = new MonitorCapture(device.Adapter, device.Output);
            capture.GotFrame += (sender, collection) => Debug.WriteLine("Got frame");
            _captures.Add(capture);
        }

        public void StartCapture()
        {
            foreach (var capture in _captures)
                capture.StartCapturing();
        }

        public void StopCapture()
        {
            foreach (var capture in _captures)
                capture.StopCapturing();
        }

        #endregion Public Methods
    }
}