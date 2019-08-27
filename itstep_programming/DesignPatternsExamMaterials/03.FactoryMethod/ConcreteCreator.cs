using _03.FactoryMethod.Abstraction;

namespace _03.FactoryMethod
{
    internal class ConcreteCreator : AbstractCreator
    {
        public override AbstractProduct Create()
        {
            return new ConcreteProduct();
        }
    }
}
