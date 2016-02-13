namespace Solid.Arduino
{
    /// <summary>
    /// Event arguments passed to a <see cref="StringReceivedHandler"/> type event.
    /// </summary>
    /// <see cref="StringReceivedHandler"/>
    /// <see cref="ArduinoSession.StringReceived"/>
    public class StringEventArgs
    {
        #region Private Fields

        private readonly string _text;

        #endregion Private Fields

        #region Public Properties

        /// <summary>
        /// Gets the string value being received.
        /// </summary>
        public string Text { get { return _text; } }

        #endregion Public Properties

        #region Internal Constructors

        internal StringEventArgs(string text)
        {
            _text = text;
        }

        #endregion Internal Constructors
    }
}