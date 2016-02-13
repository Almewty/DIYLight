namespace Solid.Arduino.Firmata
{
    /// <summary>
    /// Represents the Firmata communication protocol version.
    /// </summary>
    public struct ProtocolVersion
    {
        #region Public Properties

        /// <summary>
        /// Gets or sets the major version number.
        /// </summary>
        public int Major { get; set; }

        /// <summary>
        /// Gets or sets the minor version number.
        /// </summary>
        public int Minor { get; set; }

        #endregion Public Properties
    }
}