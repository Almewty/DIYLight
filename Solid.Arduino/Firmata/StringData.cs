namespace Solid.Arduino.Firmata
{
    /// <summary>
    /// Represents a string exchanged with the Firmata SYSEX STRING_DATA command.
    /// </summary>
    public struct StringData
    {
        #region Public Properties

        /// <summary>
        /// Gets or sets the string.
        /// </summary>
        public string Text { get; set; }

        #endregion Public Properties
    }
}