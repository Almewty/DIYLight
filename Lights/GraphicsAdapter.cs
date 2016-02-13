using SharpDX.DXGI;
using System.Collections.Generic;
using System.Linq;

namespace RustyDevelopment.AmbiLED
{
    public class GraphicsAdapter
    {
        #region Public Properties

        public Adapter1 Adapter { get; }

        public IEnumerable<OutputDevice> OutputDevices
            => Adapter.Outputs.Select(o => new OutputDevice(Adapter, o.QueryInterface<Output1>()));

        #endregion Public Properties

        #region Public Constructors

        public GraphicsAdapter(Adapter1 adapter)
        {
            Adapter = adapter;
        }

        #endregion Public Constructors

        #region Public Methods

        public override bool Equals(object obj)
        {
            var adapter = obj as GraphicsAdapter;
            return adapter != null && adapter.Adapter.Equals(Adapter);
        }

        public override int GetHashCode()
        {
            return Adapter.GetHashCode();
        }

        public override string ToString()
        {
            return Adapter.Description1.Description.TrimEnd('\0');
        }

        #endregion Public Methods
    }
}