namespace Solid.Arduino.I2C
{
    /// <summary>
    /// Container for an I2C message
    /// </summary>
    public struct I2CReply
    {
        #region Public Properties

        /// <summary>
        /// Gets or sets the memory address.
        /// </summary>
        public int Address { get; set; }

        /// <summary>
        /// Gets or sets the binary data.
        /// </summary>
        public byte[] Data { get; set; }

        /// <summary>
        /// Gets or sets the register number.
        /// </summary>
        public int Register { get; set; }

        #endregion Public Properties
    }
}