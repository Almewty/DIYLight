using System.Drawing;

namespace RustyDevelopment.AmbiLED.Processors
{
    public interface IProcessor
    {
        #region Public Methods

        Color Process(byte index, Color color);

        #endregion Public Methods
    }
}