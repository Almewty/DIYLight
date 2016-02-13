using System;

namespace RustyDevelopment.AmbiLED
{
    public unsafe class PixelCollection
    {
        #region Private Fields

        private readonly Pixel* _data;

        #endregion Private Fields

        #region Public Properties

        public int Height { get; }
        public int Width { get; }

        #endregion Public Properties

        #region Public Constructors

        public PixelCollection(IntPtr data, int height, int width)
        {
            _data = (Pixel*)data;
            Height = height;
            Width = width;
        }

        #endregion Public Constructors

        #region Public Indexers

        public Pixel this[int index] => *(_data + index);

        #endregion Public Indexers
    }
}