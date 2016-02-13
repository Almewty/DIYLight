using Solid.Arduino;
using System;

namespace RustyDevelopment.AmbiLED
{
    public class Leds
    {
        #region Private Fields

        private const byte FlushColorsCommand = 0x04;
        private const byte QueueColorCommand = 0x03;
        private const byte SetHueCommand = 0x01;
        private const byte SetRgbCommand = 0x02;
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

        public void SetRGB(byte r, byte g, byte b)
        {
            _session.SendSysExCommand(SetRgbCommand, r, g, b);
        }

        #endregion Public Methods
    }
}