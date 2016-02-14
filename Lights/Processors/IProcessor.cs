using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RustyDevelopment.AmbiLED.Processors
{
    public interface IProcessor
    {
        Color Process(byte index, Color color);
    }
}
