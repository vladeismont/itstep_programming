using System.Collections.Generic;
using _01.Bridge.Abstraction;

namespace _01.Bridge
{
    class Parser
    {
        private readonly DataReader _reader;
        private readonly ILineTransformer _transformer;

        public Parser(DataReader reader, ILineTransformer transformer)
        {
            _reader = reader;
            _transformer = transformer;
        }

        public IEnumerable<DataItem> ParseFile(string filePath)
        {
            return _reader.ReadData(filePath, _transformer);
        }
    }
}
