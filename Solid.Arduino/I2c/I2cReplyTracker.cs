﻿namespace Solid.Arduino.I2C
{
    internal class I2CReplyTracker : ObservableEventTracker<II2CProtocol, I2CReply>
    {
        #region Constructors

        internal I2CReplyTracker(II2CProtocol ii2C) : base(ii2C)
        {
            TrackingSource.I2CReplyReceived += I2CReplyReceived;
        }

        #endregion Constructors

        #region Public Methods

        public override void Dispose()
        {
            if (!IsDisposed)
            {
                TrackingSource.I2CReplyReceived -= I2CReplyReceived;
                base.Dispose();
            }
        }

        #endregion Public Methods

        #region Private Methods

        private void I2CReplyReceived(object parSender, I2CEventArgs parEventArgs)
        {
            Observers.ForEach(o => o.OnNext(parEventArgs.Value));
        }

        #endregion Private Methods
    }
}