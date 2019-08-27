using System;
using _01.AbstractFactory.Abstraction;

namespace _01.AbstractFactory.Implementation
{
    internal class ElementA : IElementA
    {
        public void InteractWith(IElementB elementB)
        {
            Console.WriteLine($"{nameof(ElementA)} interacts with {nameof(ElementB)}");
        }
    }
}