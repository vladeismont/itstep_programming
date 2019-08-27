using _01.AbstractFactory.Abstraction;

namespace _01.AbstractFactory.Implementation
{
    internal class Factory : IFactory
    {
        public IElementA CreateElementA()
        {
            return new ElementA();
        }

        public IElementB CreateElementB()
        {
            return new ElementB();
        }
    }
}