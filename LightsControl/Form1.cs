using RustyDevelopment.AmbiLED;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LightsControl
{
    public partial class Form1 : Form
    {
        #region Private Fields

        private Leds _leds;
        private CancellationTokenSource cancelTokenSource;
        private List<MonitorCapture> captures;
        private Dictionary<MonitorCapture, Task> captureTasks;
        private Dictionary<MonitorCapture, Tuple<int, int, int, int>> usedScreens;
        private bool _useColorBoost = true;
        private bool _useMinColor = true;

        #endregion Private Fields

        #region Public Constructors

        public Form1()
        {
            InitializeComponent();
            usedScreens = new Dictionary<MonitorCapture, Tuple<int, int, int, int>>();
            captures = new List<MonitorCapture>();
            captureTasks = new Dictionary<MonitorCapture, Task>();
        }

        #endregion Public Constructors

        #region Private Methods

        private void btnStart_Click(object sender, EventArgs e)
        {
            Start();
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            Stop();
            SetState(false);
        }

        private void SetState(bool running)
        {
            _btnStart.Enabled = !running;
            _btnStop.Enabled = running;
            _numLeft.Enabled = !running;
            _numRight.Enabled = !running;
            _numTop.Enabled = !running;
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (_leds == null)
                return;
            Stop();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                _leds = new Leds();
            }
            catch (InvalidOperationException)
            {
                MessageBox.Show("No firmata arduino found");
                Application.Exit();
            }

            var desktop = new MonitorCapture(0, 0);
            var screen = Screen.PrimaryScreen.Bounds;
            _resolutionLabel.Text = $"{screen.Width}x{screen.Height}";

            desktop.ProcessColor += (index, r, g, b) =>
            {
                var rgb = Color.FromArgb(r, g, b);
                if (_useColorBoost)
                {
                    var hsv = ColorSpace.RGB2HSV(Color.FromArgb(r, g, b));
                    hsv[1] = Math.Min(1f, hsv[1] * 1.5f);
                    rgb = ColorSpace.HSV2RGB(hsv);
                }
                if (_useMinColor)
                {
                    if (rgb.R <= 30 && rgb.G <= 30 && rgb.B <= 30)
                        rgb = Color.Black;
                }
                _leds.QueueColor(index, rgb.R, rgb.G, rgb.B);
            };

            captures.Add(desktop);
        }

        private void Start()
        {
            if (cancelTokenSource != null && !cancelTokenSource.IsCancellationRequested)
                return;
            SetState(true);
            int left = (int)_numLeft.Value;
            int top = (int)_numTop.Value;
            int right = (int)_numRight.Value;
            _leds.SetLedCount((byte)(left + top + right));
            cancelTokenSource = new CancellationTokenSource();
            foreach (var desktop in captures)
            {
                desktop.Filter.Clear();
                var screen = Screen.PrimaryScreen.Bounds;
                for (int i = 0; i < left; i++)
                    desktop.Filter.Add((byte)(left - 1 - i), new Rectangle(0, (i * screen.Height) / left, 200, screen.Height / left));
                for (int i = 0; i < top; i++)
                    desktop.Filter.Add((byte)(left + i), new Rectangle(i * screen.Width / top, 0, screen.Width / top, 150));
                for (int i = 0; i < right; i++)
                    desktop.Filter.Add((byte) (left + top + i),
                        new Rectangle(screen.Width - 200, (i * screen.Height) / right, 200, screen.Height / right));

                captureTasks.Add(desktop, Task.Run(() =>
                {
                    while (!cancelTokenSource.IsCancellationRequested)
                    {
                        desktop.Capture();
                        _leds.FlushColors();
                    }
                }));
            }
        }

        private void Stop()
        {
            if (cancelTokenSource == null)
                return;
            cancelTokenSource.Cancel();
            Task.WaitAll(captureTasks.Values.ToArray());
            captureTasks.Clear();
            Task.Delay(100).ContinueWith((tsk) => _leds.SetRgb(0, 0, 0)).Wait();
        }

        #endregion Private Methods

        private void _chkColorBoost_CheckedChanged(object sender, EventArgs e)
        {
            _useColorBoost = _chkColorBoost.Checked;
        }

        private void _chkMinColor_CheckedChanged(object sender, EventArgs e)
        {
            _useMinColor = _chkMinColor.Checked;
        }
    }
}