using System;
using System.Windows.Forms;

namespace LightsControl
{
    internal static class Program
    {
        #region Private Methods

        /// <summary>
        /// Der Haupteinstiegspunkt für die Anwendung.
        /// </summary>
        [STAThread]
        private static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }

        #endregion Private Methods
    }
}