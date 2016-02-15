using Solid.Arduino;
using System;
using System.Drawing;

namespace RustyDevelopment.AmbiLED
{
    public class Leds
    {
        #region Private Fields

        private const byte FlushColorsCommand = 0x04;
        private const byte QueueColorCommand = 0x03;
        private const byte SetHueCommand = 0x01;
        private const byte SetRgbCommand = 0x02;
        private const byte SetLedsCommand = 0x05;
        private readonly ArduinoSession _session;

        #endregion Private Fields

        #region Public Constructors

        public Leds()
        {
            var serial = SerialConnection.FindSerialConnection();
            if (serial == null)
                throw new InvalidOperationException();
            _session = new ArduinoSession(serial);
        }

        #endregion Public Constructors

        #region Public Methods

        public void FlushColors()
        {
            _session.SendSysExCommand(FlushColorsCommand);
        }

        public void QueueColor(byte index, byte r, byte g, byte b)
        {
            _session.SendSysExCommand(QueueColorCommand, index, r, g, b);
        }

        public void SetHue(byte hue)
        {
            _session.SendSysExCommand(SetHueCommand, hue);
        }

        public void SetRgb(byte r, byte g, byte b)
        {
            _session.SendSysExCommand(SetRgbCommand, r, g, b);
        }

        public void SetLeds(Tuple<byte, Color>[] ledData)
        {
            byte length = (byte)ledData.Length;
            var data = new byte[length * 4 + 1];
            data[0] = length;
            for (int i = 0; i < ledData.Length; ++i)
            {
                int offset = i * 4 + 1;
                Color c = ledData[i].Item2;
                data[offset] = ledData[i].Item1;
                data[offset + 1] = c.R;
                data[offset + 2] = c.G;
                data[offset + 3] = c.B;
            }
            _session.SendSysExCommand(SetLedsCommand, data);
        }

        #endregion Public Methods
    }
}