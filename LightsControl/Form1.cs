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
        
        private CancellationTokenSource cancelTokenSource;
        private List<MonitorCapture> captures;
        private Dictionary<MonitorCapture, Task> captureTasks;
        private Dictionary<MonitorCapture, Tuple<int, int, int, int>> usedScreens;

        #endregion Private Fields

        #region Public Constructors

        public Form1()
        {
            InitializeComponent();
            usedScreens = new Dictionary<MonitorCapture, Tuple<int, int, int, int>>();
            cancelTokenSource = new CancellationTokenSource();
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
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            //var desktop = new MonitorCapture(0, 0);
            var screen = Screen.PrimaryScreen.Bounds;

            var filters = new Dictionary<int, Rectangle>();

            for (int i = 0; i < 10; i++)
                filters.Add((byte)(9 - i), new Rectangle(0, (i * 1080) / 10, 200, 1080 / 10));
            for (int i = 0; i < 17; i++)
                filters.Add((byte)(10 + i), new Rectangle((i * 1920) / 17, 0, 1920 / 17, 150));

            try
            {

                CaptureManager man = new CaptureManager();
                man.AddCapture(man.GraphicsAdapters.First().OutputDevices.First(), filters);
                man.StartCapture();
            }
            catch (InvalidOperationException)
            {
                MessageBox.Show("No firmata arduino found");
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
            cancelTokenSource = new CancellationTokenSource();
            foreach (var desktop in captures)
            {
                desktop.StartCapturing();
                //captureTasks.Add(desktop, Task.Run(() =>
                //{
                //    while (!cancelTokenSource.IsCancellationRequested)
                //    {
                //        //desktop.Capture();
                //        _leds.FlushColors();
                //    }
                //}));
            }
        }

        private void Stop()
        {
            cancelTokenSource.Cancel();
            Task.WaitAll(captureTasks.Values.ToArray());
            captureTasks.Clear();
        }

        #endregion Private Methods
    }
}