using Solid.Arduino;
using System;
using System.Collections.Generic;
using System.Drawing;
using RustyDevelopment.AmbiLED.Dummy;

namespace RustyDevelopment.AmbiLED
{
    public class Leds
    {
        #region Private Fields

        private const byte FlushColorsCommand = 0x04;
        private const int MaxPackageSize = 64;
        private const byte QueueColorCommand = 0x03;
        private const byte SetHueCommand = 0x01;
        private const byte SetLedsCommand = 0x05;
        private const byte SetRgbCommand = 0x02;
        private readonly ArduinoSession _session;

        #endregion Private Fields

        #region Public Constructors

        public Leds()
        {
            //var serial = new SerialConnection("COM3", SerialBaudRate.Bps115200);
            var serial = new EmulatorConnection();
            //var serial = SerialConnection.FindSerialConnection();
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

        public void SetLeds(Tuple<byte, Color>[] ledData)
        {
            int maxLength = ((MaxPackageSize - 1) * 7 / 8 - 1) / 4;
            int done = 0;
            int totalLength = ledData.Length;
            List<byte> message = new List<byte>();
            while (done < totalLength)
            {
                int length = Math.Min(maxLength, totalLength - done);
                var data = new byte[length * 4 + 1];
                data[0] = (byte)length;
                for (int i = done; i < length + done; ++i)
                {
                    int offset = (i - done) * 4 + 1;
                    Color c = ledData[i].Item2;
                    data[offset] = ledData[i].Item1;
                    data[offset + 1] = c.R;
                    data[offset + 2] = c.G;
                    data[offset + 3] = c.B;
                }
                message.AddRange(_session.BuildSysExMessage(SetLedsCommand,
                    data));
                done += length;
            }
            _session.SendRaw(message.ToArray());
        }

        public void SetRgb(byte r, byte g, byte b)
        {
            _session.SendSysExCommand(SetRgbCommand, r, g, b);
        }

        #endregion Public Methods
    }
}