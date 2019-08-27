using System.Collections.Generic;

namespace _01.Bridge.Abstraction
{
    abstract class DataReader
    {
        public abstract IEnumerable<DataItem> ReadData(string filePath, ILineTransformer transformer);
    }
}