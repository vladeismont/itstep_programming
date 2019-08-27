using _02.Builder.HouseParts;

namespace _02.Builder
{
    internal class ConcreteBuilder : Builder
    {
        private readonly House _house = new House();

        public override void BuildBasement()
        {
            _house.Add(new Basement());
        }

        public override void BuildStorey()
        {
            _house.Add(new Store());
        }

        public override void BuildRoof()
        {
            _house.Add(new Roof());
        }

        public override House GetResult()
        {
            return _house;
        }
    }
}