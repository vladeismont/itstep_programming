using _01.AbstractFactory.Abstraction;

namespace _01.AbstractFactory.Implementation
{
    internal class Client
    {
        private readonly IElementA _elementA;
        private readonly IElementB _elementB;

        public Client(IFactory factory)
        {
            _elementA = factory.CreateElementA();
            _elementB = factory.CreateElementB();
        }

        public void Run()
        {
            _elementA.InteractWith(_elementB);
        }
    }
}
