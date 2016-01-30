using Solid.Arduino;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Arduino.Lights
{
    public class Lights
    {
        private const byte SetHueCommand = 0x01;
        private const byte SetRgbCommand = 0x02;
        private const byte QueueColorCommand = 0x03;
        private const byte FlushColorsCommand = 0x04;
        private ArduinoSession session;

        public Lights()
        {
            var serial = SerialConnection.FindSerialConnection();
            if (serial == null)
                throw new InvalidOperationException();
            session = new ArduinoSession(serial);
        }

        public void SetHue(byte hue)
        {
            session.SendSysExCommand(SetHueCommand, hue);
        }

        public void SetRGB(byte r, byte g, byte b)
        {
            session.SendSysExCommand(SetRgbCommand, r, g, b);
        }

        public void QueueColor(byte index, byte r, byte g, byte b)
        {
            session.SendSysExCommand(QueueColorCommand, index, r, g, b);
        }

        public void FlushColors()
        {
            session.SendSysExCommand(FlushColorsCommand);
        }
    }
}
