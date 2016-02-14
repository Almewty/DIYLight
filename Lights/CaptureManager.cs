using System;
using SharpDX.DXGI;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Security.Principal;
using Solid.Arduino;

namespace RustyDevelopment.AmbiLED
{
    public class CaptureManager
    {
        #region Private Fields

        private readonly Factory1 _factory;

        private readonly Dictionary<MonitorCapture, Dictionary<int, Rectangle>> _screenRegions;
        private readonly Leds _leds;

        #endregion Private Fields

        #region Public Properties

        public IReadOnlyList<MonitorCapture> Captures =>
            _screenRegions.Keys.Cast<MonitorCapture>() as IReadOnlyList<MonitorCapture>;

        public IEnumerable<GraphicsAdapter> GraphicsAdapters =>
            _factory.Adapters1.Select(a => new GraphicsAdapter(a));

        public IReadOnlyDictionary<MonitorCapture, IReadOnlyDictionary<int, Rectangle>> ScreenRegions
            =>
                _screenRegions.Select(
                    kvp => new KeyValuePair<MonitorCapture, IReadOnlyDictionary<int, Rectangle>>(kvp.Key, kvp.Value))
                    .ToDictionary(kvp => kvp.Key, kvp => kvp.Value);

        #endregion Public Properties

        #region Public Constructors

        public CaptureManager()
        {
            _factory = new Factory1();
            _screenRegions = new Dictionary<MonitorCapture, Dictionary<int, Rectangle>>();
            _leds = new Leds();
        }

        #endregion Public Constructors

        #region Public Methods

        public void AddCapture(OutputDevice device)
        {
            AddCapture(device, new Dictionary<int, Rectangle>());
        }

        public void AddCapture(OutputDevice device, Dictionary<int, Rectangle> regions)
        {
            var capture = new MonitorCapture(device.Adapter, device.Output);
            capture.GotFrame += Capture_GotFrame;
            _screenRegions.Add(capture, regions);
        }

        private void Capture_GotFrame(object sender, PixelCollection pixelCollection)
        {
            var capture = sender as MonitorCapture;
            if (capture == null)
                return;
            foreach (var ledRegion in _screenRegions[capture])
            {
                int index = ledRegion.Key;
                Color color = Condensor.Condense(pixelCollection, ledRegion.Value);
                _leds.QueueColor((byte) index, color.R, color.G, color.B);
            }
            _leds.FlushColors();
        }

        public void RemoveCapture(MonitorCapture capture)
        {
            _screenRegions.Remove(capture);
        }

        public void StartCapture()
        {
            foreach (var capture in _screenRegions.Keys)
                capture.StartCapturing();
        }

        public void StopCapture()
        {
            foreach (var capture in _screenRegions.Keys)
                capture.StopCapturing();
        }

        #endregion Public Methods
    }
}