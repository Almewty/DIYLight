using System;

namespace Solid.Arduino.Firmata
{
    /// <summary>
    /// Contains event data for a <see cref="AnalogStateReceivedHandler"/> and <see cref="DigitalStateReceivedHandler"/> type events.
    /// </summary>
    /// <typeparam name="T">Type of the event data</typeparam>
    /// <remarks>
    /// This class is primarily implemented by the <see cref="IFirmataProtocol.AnalogStateReceived"/> and <see cref="IFirmataProtocol.DigitalStateReceived"/> events.
    /// </remarks>
    /// <seealso cref="AnalogStateReceivedHandler"/>
    /// <seealso cref="DigitalStateReceivedHandler"/>
    public class FirmataEventArgs<T> : EventArgs
        where T : struct
    {
        #region Private Fields

        private readonly T _value;

        #endregion Private Fields

        #region Public Properties

        /// <summary>
        /// Gets the received message.
        /// </summary>
        public T Value { get { return _value; } }

        #endregion Public Properties

        #region Internal Constructors

        internal FirmataEventArgs(T value)
        {
            _value = value;
        }

        #endregion Internal Constructors
    }
}