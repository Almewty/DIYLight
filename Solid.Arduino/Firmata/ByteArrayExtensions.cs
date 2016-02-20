﻿using System;

namespace Solid.Arduino.Firmata
{
    /// <summary>
    /// Provides extension methods for <see cref="byte"/> arrays.
    /// </summary>
    public static class ByteArrayExtensions
    {
        #region Public Methods

        /// <summary>
        /// Converts a <see cref="byte"/> array holding binary coded digits to a readable string.
        /// </summary>
        /// <param name="data">The binary coded digit bytes</param>
        /// <param name="isLittleEndian">Value indicating if the first nibble contains the least significant part</param>
        /// <returns>A string containing numeric data</returns>
        /// <exception cref="ArgumentException">The array contains one or more non-BCD bytes.</exception>
        public static string ConvertBinaryCodedDecimalToString(this byte[] data, bool isLittleEndian = false)
        {
            if (data == null)
                throw new ArgumentNullException();

            if (data.Length == 0)
                return string.Empty;

            char[] chars = new char[data.Length * 2];
            int charIndex = 0;

            if (isLittleEndian)
            {
                for (int x = data.Length - 1; x >= 0; x--)
                {
                    chars[charIndex++] = ConvertToChar(data[x] & 0x0F);
                    chars[charIndex++] = ConvertToChar(data[x] >> 4);
                }
            }
            else
            {
                foreach (byte b in data)
                {
                    chars[charIndex++] = ConvertToChar(b >> 4);
                    chars[charIndex++] = ConvertToChar(b & 0x0F);
                }
            }

            return new string(chars);
        }

        #endregion Public Methods

        #region Private Methods

        private static char ConvertToChar(int code)
        {
            if (code > 9)
                throw new ArgumentException(Messages.ArgumentEx_CannotConvertBcd);

            return Convert.ToChar(code | 0x30);
        }

        #endregion Private Methods
    }
}