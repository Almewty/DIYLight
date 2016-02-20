using System.Drawing;

namespace RustyDevelopment.AmbiLED
{
    public class Condensor
    {
        #region Public Methods

        public static Color Condense(PixelCollection pixels, Rectangle region)
        {
            long r = 0;
            long g = 0;
            long b = 0;
            for (int x = region.Left; x < region.Right; ++x)
            {
                for (int y = region.Top; y < region.Bottom; ++y)
                {
                    var pixel = pixels[pixels.Width * y + x];
                    r += pixel.Red;
                    g += pixel.Green;
                    b += pixel.Blue;
                }
            }
            int pixelCount = region.Width * region.Height;
            return Color.FromArgb((byte)(r / pixelCount), (byte)(g / pixelCount), (byte)(b / pixelCount));
        }

        #endregion Public Methods
    }
}