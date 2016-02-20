using RustyDevelopment.AmbiLED;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using LightsControl.Properties;

namespace LightsControl
{
    public partial class Form1 : Form
    {
        #region Private Fields

        private readonly CancellationTokenSource _cancelTokenSource;
        private readonly Dictionary<MonitorCapture, Task> _captureTasks;

        #endregion Private Fields

        #region Public Constructors

        public Form1()
        {
            InitializeComponent();
            _cancelTokenSource = new CancellationTokenSource();
            _captureTasks = new Dictionary<MonitorCapture, Task>();
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
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            var filters = new Dictionary<byte, Rectangle>();

            for (int i = 0; i < 10; i++)
                filters.Add((byte)(9 - i), new Rectangle(0, i * 1080 / 10, 200, 1080 / 10));
            for (int i = 0; i < 17; i++)
                filters.Add((byte)(10 + i), new Rectangle(i * 1920 / 17, 0, 1920 / 17, 150));

            try
            {
                CaptureManager man = new CaptureManager();
                man.AddCapture(man.GraphicsAdapters.First().OutputDevices.First(), filters);
                man.StartCapture();
            }
            catch (InvalidOperationException)
            {
                MessageBox.Show(Resources.No_firmata_arduino_found);
                Application.Exit();
            }

            //desktop.ProcessColor += (index, r, g, b) =>
            //{
            //    var hsv = ColorSpace.RGB2HSV(Color.FromArgb(r, g, b));
            //    hsv[1] = Math.Min(1f, hsv[1] * 1.5f);
            //    var rgb = ColorSpace.HSV2RGB(hsv);
            //    if (rgb.R <= 30 && rgb.G <= 30 && rgb.B <= 30)
            //        rgb = Color.Black;
            //    _leds.QueueColor(index, rgb.R, rgb.G, rgb.B);
            //};

            //captures.Add(desktop);
        }

        private void Start()
        {
        }

        private void Stop()
        {
            _cancelTokenSource.Cancel();
            Task.WaitAll(_captureTasks.Values.ToArray());
            _captureTasks.Clear();
        }

        #endregion Private Methods
    }
}