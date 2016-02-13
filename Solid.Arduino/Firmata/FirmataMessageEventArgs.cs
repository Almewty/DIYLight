using System;

namespace Solid.Arduino.Firmata
{
    /// <summary>
    /// Event arguments passed to a <see cref="MessageReceivedHandler"/> type event.
    /// </summary>
    /// <see cref="MessageReceivedHandler"/>
    public class FirmataMessageEventArgs : EventArgs
    {
        #region Private Fields

        private readonly FirmataMessage _value;

        #endregion Private Fields

        #region Public Properties

        /// <summary>
        /// Gets the received message.
        /// </summary>
        public FirmataMessage Value { get { return _value; } }

        #endregion Public Properties

        #region Internal Constructors

        internal FirmataMessageEventArgs(FirmataMessage value)
        {
            _value = value;
        }

        #endregion Internal Constructors
    }
}