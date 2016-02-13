﻿namespace Solid.Arduino.Firmata
{
    /// <summary>
    /// Represents a summary of mappings between MIDI channels and physical pin numbers.
    /// </summary>
    public struct BoardAnalogMapping
    {
        #region Public Properties

        /// <summary>
        /// Gets the channel mapping array of the board's analog pins.
        /// </summary>
        public AnalogPinMapping[] PinMappings { get; internal set; }

        #endregion Public Properties
    }
}