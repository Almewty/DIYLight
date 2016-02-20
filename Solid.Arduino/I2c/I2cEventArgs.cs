using System;

namespace Solid.Arduino.I2C
{
    /// <summary>
    /// Event arguments passed to a <see cref="I2CReplyReceivedHandler"/> type event.
    /// </summary>
    public class I2CEventArgs : EventArgs
    {
        #region Private Fields

        #endregion Private Fields

        #region Public Properties

        /// <summary>
        /// Gets the I2C message value being received.
        /// </summary>
        public I2CReply Value { get; }

        #endregion Public Properties

        #region Internal Constructors

        internal I2CEventArgs(I2CReply value)
        {
            Value = value;
        }

        #endregion Internal Constructors
    }
}