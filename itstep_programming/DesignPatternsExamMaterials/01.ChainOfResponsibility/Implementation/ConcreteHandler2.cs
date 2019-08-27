using System;
using _01.ChainOfResponsibility.Abstraction;

namespace _01.ChainOfResponsibility.Implementation
{
    class ConcreteHandler2 : Handler
    {
        public override void HandleRequest(int request)
        {
            if (request == 2)
                Console.WriteLine("Two");
            else
                Successor?.HandleRequest(request);
        }
    }
}