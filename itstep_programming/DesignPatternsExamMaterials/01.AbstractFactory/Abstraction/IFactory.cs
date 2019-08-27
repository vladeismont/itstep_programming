namespace _01.AbstractFactory.Abstraction
{
    internal interface IFactory
    {
        IElementA CreateElementA();

        IElementB CreateElementB();
    }
}