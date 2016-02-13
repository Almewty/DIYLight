using SharpDX.DXGI;

namespace RustyDevelopment.AmbiLED
{
    public class OutputDevice
    {
        #region Public Properties

        public Adapter1 Adapter { get; }
        public Output1 Output { get; }

        #endregion Public Properties

        #region Public Constructors

        public OutputDevice(Adapter1 adapter, Output1 output)
        {
            Adapter = adapter;
            Output = output;
        }

        #endregion Public Constructors

        #region Public Methods

        public override bool Equals(object obj)
        {
            var output = obj as OutputDevice;
            return output != null && output.Output.Equals(Output);
        }

        public override int GetHashCode()
        {
            return Output.GetHashCode();
        }

        public override string ToString()
        {
            return Output.Description.DeviceName;
        }

        #endregion Public Methods
    }
}