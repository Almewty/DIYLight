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

        #endregion Private Fields

        #region Public Properties

        /// <summary>
        /// Gets the received message.
        /// </summary>
        public FirmataMessage Value { get; }

        #endregion Public Properties

        #region Internal Constructors

        internal FirmataMessageEventArgs(FirmataMessage value)
        {
            Value = value;
        }

        #endregion Internal Constructors
    }
}