using System;
using System.CodeDom;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Solid.Arduino;

namespace RustyDevelopment.AmbiLED.Dummy
{
    public class EmulatorConnection : ISerialConnection
    {
        public void Dispose()
        {
        }

        public int BaudRate { get; set; }
        public int BytesToRead => 0;
        public bool IsOpen { get; private set; }
        public string NewLine { get; set; } = "\n";
        public string PortName { get; set; }
        public event SerialDataReceivedEventHandler DataReceived;

        public void Close()
        {
            IsOpen = false;
        }

        [DllImport("ArduSim.dll")]
        public static extern void write(byte[] buffer, int length);

        public void Open()
        {
            IsOpen = true;
        }

        public int ReadByte()
        {
            return -1;
        }

        public void Write(string text)
        {
            byte[] data = Encoding.ASCII.GetBytes(text);
            write(data, data.Length);
        }

        public void Write(byte[] buffer, int offset, int count)
        {
            write(buffer.Skip(offset).ToArray(), count);
        }

        public void WriteLine(string text)
        {
            Write(text + NewLine);
        }
    }
}
