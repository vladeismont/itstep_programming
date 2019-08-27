using System.Collections.Generic;
using System.IO;
using System.Linq;
using _01.Bridge.Abstraction;

namespace _01.Bridge.Implementation
{
    class TxtFileDataReader : DataReader 
    {
        public override IEnumerable<DataItem> ReadData(string filePath, ILineTransformer transformer)
            => File.ReadAllLines(filePath).Select(transformer.Transform);
    }
}
