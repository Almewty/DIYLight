namespace Solid.Arduino.Firmata
{
    /// <summary>
    /// Represents a summary of pinmode capabilities supported by an Arduino board.
    /// </summary>
    public struct BoardCapability
    {
        #region Public Properties

        /// <summary>
        /// Gets the capability array of the board's pins.
        /// </summary>
        public PinCapability[] PinCapabilities { get; internal set; }

        #endregion Public Properties
    }
}