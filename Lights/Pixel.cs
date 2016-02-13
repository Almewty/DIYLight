using System.Runtime.InteropServices;

namespace RustyDevelopment.AmbiLED
{
    [StructLayout(LayoutKind.Sequential, Pack = 0)]
    public struct Pixel
    {
        public byte Blue;
        public byte Green;
        public byte Red;
        public byte Alpha;
    }
}