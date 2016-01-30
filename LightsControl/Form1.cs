using Arduino.Lights;
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
        private List<DesktopCapture> captures;
        private Dictionary<DesktopCapture, Task> captureTasks;
        private Lights lights;
        private Dictionary<DesktopCapture, Tuple<int, int, int, int>> usedScreens;

        #endregion Private Fields

        #region Public Constructors

        public Form1()
        {
            InitializeComponent();
            usedScreens = new Dictionary<DesktopCapture, Tuple<int, int, int, int>>();
            cancelTokenSource = new CancellationTokenSource();
            captures = new List<DesktopCapture>();
            captureTasks = new Dictionary<DesktopCapture, Task>();
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
            try
            {
                lights = new Lights();
            }
            catch (InvalidOperationException)
            {
                MessageBox.Show("No firmata arduino found");
                Application.Exit();
            }

            var desktop = new DesktopCapture(lights, 0, 0);
            var screen = Screen.PrimaryScreen.Bounds;

            for (int i = 0; i < 10; i++)
                desktop.Filter.Add((byte)(9 - i), new Rectangle(0, (i * 1080) / 10, 200, 1080 / 10));
            for (int i = 0; i < 17; i++)
                desktop.Filter.Add((byte)(10 + i), new Rectangle((i * 1920) / 17, 0, 1920 / 17, 150));

            captures.Add(desktop);
        }

        private void Start()
        {
            cancelTokenSource = new CancellationTokenSource();
            foreach (var desktop in captures)
            {
                captureTasks.Add(desktop, Task.Run(() =>
                {
                    while (!cancelTokenSource.IsCancellationRequested)
                        desktop.Capture();
                }));
            }
        }

        private void Stop()
        {
            cancelTokenSource.Cancel();
            Task.WaitAll(captureTasks.Values.ToArray());
            captureTasks.Clear();
            Task.Delay(100).ContinueWith((tsk) => lights.SetRGB(0, 0, 0));
        }

        #endregion Private Methods
    }
}