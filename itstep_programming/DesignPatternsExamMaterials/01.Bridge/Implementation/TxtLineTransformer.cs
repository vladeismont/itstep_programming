using _01.Bridge.Abstraction;

namespace _01.Bridge.Implementation
{
    class TxtLineTransformer : ILineTransformer
    {
        public DataItem Transform(string line)
        {
            var splittedLine = line.Split(';');
            return new DataItem
            {
                Name = splittedLine[0],
                Organisation = splittedLine[1]
            };
        }
    }
}
