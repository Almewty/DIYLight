using System;

namespace Solid.Arduino.Firmata
{
    /// <summary>
    /// Indicates the type of a Firmata Message.
    /// </summary>
    public enum MessageType
    {
        #region Public Fields

        AnalogState,
        DigitalPortState,
        ProtocolVersion,
        FirmwareResponse,
        CapabilityResponse,
        AnalogMappingResponse,
        PinStateResponse,
        StringData,
        I2CReply

        #endregion Public Fields
    }

    /// <summary>
    /// Represents a Firmata message received from an Arduino or Arduino compatible system.
    /// </summary>
    public class FirmataMessage
    {
        #region Private Fields

        #endregion Private Fields

        #region Public Properties

        /// <summary>
        /// Gets the time of the delivered message.
        /// </summary>
        public DateTime Time { get; }

        /// <summary>
        /// Gets the type enumeration of the message.
        /// </summary>
        public MessageType Type { get; }

        /// <summary>
        /// Gets the specific value delivered by the message.
        /// </summary>
        public ValueType Value { get; }

        #endregion Public Properties

        #region Internal Constructors

        /// <summary>
        /// Initializes a new <see cref="FirmataMessage"/> instance.
        /// </summary>
        /// <param name="type">The type of message to be created.</param>
        internal FirmataMessage(MessageType type) : this(null, type, DateTime.UtcNow)
        {
        }

        /// <summary>
        /// Initializes a new <see cref="FirmataMessage"/> instance.
        /// </summary>
        /// <param name="value"></param>
        /// <param name="type"></param>
        internal FirmataMessage(ValueType value, MessageType type) : this(value, type, DateTime.UtcNow)
        {
        }

        /// <summary>
        /// Initializes a new <see cref="FirmataMessage"/> instance.
        /// </summary>
        /// <param name="value"></param>
        /// <param name="type"></param>
        /// <param name="time"></param>
        internal FirmataMessage(ValueType value, MessageType type, DateTime time)
        {
            Value = value;
            Type = type;
            Time = time;
        }

        #endregion Internal Constructors
    }
}