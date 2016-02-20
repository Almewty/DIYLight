using SharpDX.DXGI;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Linq;

namespace RustyDevelopment.AmbiLED
{
    public class CaptureManager
    {
        #region Private Fields

        private readonly Factory1 _factory;

        private readonly Leds _leds;
        private readonly Dictionary<MonitorCapture, Dictionary<byte, Rectangle>> _screenRegions;

        private readonly Stopwatch _stopwatch = new Stopwatch();

        #endregion Private Fields

        #region Public Properties

        public IReadOnlyList<MonitorCapture> Captures =>
            // ReSharper disable once RedundantEnumerableCastCall
                    _screenRegions.Keys.Cast<MonitorCapture>() as IReadOnlyList<MonitorCapture>;

        public IEnumerable<GraphicsAdapter> GraphicsAdapters =>
            _factory.Adapters1.Select(a => new GraphicsAdapter(a));

        public IReadOnlyDictionary<MonitorCapture, IReadOnlyDictionary<byte, Rectangle>> ScreenRegions
            =>
                _screenRegions.Select(
                    kvp => new KeyValuePair<MonitorCapture, IReadOnlyDictionary<byte, Rectangle>>(kvp.Key, kvp.Value))
                    .ToDictionary(kvp => kvp.Key, kvp => kvp.Value);

        #endregion Public Properties

        #region Public Constructors

        public CaptureManager()
        {
            _factory = new Factory1();
            _screenRegions = new Dictionary<MonitorCapture, Dictionary<byte, Rectangle>>();
            _leds = new Leds();
        }

        #endregion Public Constructors

        #region Public Methods

        public void AddCapture(OutputDevice device)
        {
            AddCapture(device, new Dictionary<byte, Rectangle>());
        }

        public void AddCapture(OutputDevice device, Dictionary<byte, Rectangle> regions)
        {
            var capture = new MonitorCapture(device.Adapter, device.Output);
            capture.GotFrame += Capture_GotFrame;
            _screenRegions.Add(capture, regions);
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

        #region Private Methods

        private void Capture_GotFrame(object sender, PixelCollection pixelCollection)
        {
            var capture = sender as MonitorCapture;
            if (capture == null)
                return;
            var ledData = new Tuple<byte, Color>[_screenRegions[capture].Count];
            int counter = 0;
            _stopwatch.Restart();
            foreach (var ledRegion in _screenRegions[capture])
            {
                byte index = ledRegion.Key;
                Color color = Condensor.Condense(pixelCollection, ledRegion.Value);

                ledData[counter++] = Tuple.Create(index, color);
                //_leds.QueueColor(index, color.R, color.G, color.B);
            }
            Debug.WriteLine($"Condensing: {_stopwatch.ElapsedMilliseconds}");
            _leds.SetLeds(ledData);
            //_leds.FlushColors();
        }

        #endregion Private Methods
    }
}