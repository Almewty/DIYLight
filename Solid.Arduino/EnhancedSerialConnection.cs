using System.IO.Ports;
using System.Linq;

namespace Solid.Arduino
{
    /// <summary>
    /// Represents a serial port connection, supporting Mono.
    /// </summary>
    /// <seealso href="http://www.mono-project.com/">The official Mono project site</seealso>
    /// <inheritdoc />
    public class EnhancedSerialConnection : EnhancedSerialPort, ISerialConnection
    {
        #region Constructors

        /// <summary>
        /// Initializes a new instance of <see cref="EnhancedSerialConnection"/> class using the highest serial port available at 115,200 bits per second.
        /// </summary>
        public EnhancedSerialConnection()
            : base(GetLastPortName(), (int)SerialBaudRate.Bps115200)
        {
            ReadTimeout = 100;
            WriteTimeout = 100;
        }

        /// <summary>
        /// Initializes a new instance of <see cref="EnhancedSerialConnection"/> class on the given serial port and at the given baud rate.
        /// </summary>
        /// <param name="portName">The port name (e.g. 'COM3')</param>
        /// <param name="baudRate">The baud rate</param>
        public EnhancedSerialConnection(string portName, SerialBaudRate baudRate)
            : base(portName, (int)baudRate)
        {
            ReadTimeout = 100;
            WriteTimeout = 100;
        }

        #endregion Constructors

        #region Public Methods & Properties

        /// <inheritdoc cref="SerialConnection.FindSerialConnection()"/>
        public static ISerialConnection FindSerialConnection()
        {
            return SerialConnection.FindSerialConnection();
        }

        /// <inheritdoc cref="SerialConnection.FindSerialConnection(string, string)"/>
        public static ISerialConnection FindSerialConnection(string query, string expectedReply)
        {
            return SerialConnection.FindSerialConnection(query, expectedReply);
        }

        /// <inheritdoc cref="SerialPort.Close"/>
        public new void Close()
        {
            if (IsOpen)
            {
                BaseStream.Flush();
                DiscardInBuffer();
                base.Close();
            }
        }

        #endregion Public Methods & Properties

        #region Private Methods

        private static string GetLastPortName()
        {
            return (from p in GetPortNames()
                    where p.StartsWith(@"/dev/ttyUSB") || p.StartsWith(@"/dev/ttyAMA") || p.StartsWith(@"/dev/ttyACM") || p.StartsWith("COM")
                    orderby p descending
                    select p).First();
        }

        #endregion Private Methods
    }
}