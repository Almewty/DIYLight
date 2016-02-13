namespace Solid.Arduino.Firmata
{
    internal class DigitalStateTracker : ObservableEventTracker<IFirmataProtocol, DigitalPortState>
    {
        #region Fields

        private readonly int _port;

        #endregion Fields

        #region Constructors

        internal DigitalStateTracker(IFirmataProtocol source, int port = -1)
            : base(source)
        {
            _port = port;
            TrackingSource.DigitalStateReceived += Firmata_DigitalStateReceived;
        }

        #endregion Constructors

        #region Public Methods

        public override void Dispose()
        {
            if (!IsDisposed)
            {
                TrackingSource.DigitalStateReceived -= Firmata_DigitalStateReceived;
                base.Dispose();
            }
        }

        #endregion Public Methods

        #region Private Methods

        private void Firmata_DigitalStateReceived(object parSender, FirmataEventArgs<DigitalPortState> parEventArgs)
        {
            if (_port >= 0 && _port != parEventArgs.Value.Port)
                return;

            Observers.ForEach(o => o.OnNext(parEventArgs.Value));
        }

        #endregion Private Methods
    }
}