using System;
using _09.Strategy.Abstraction;

namespace _09.Strategy.Implementation
{
    class StrategyA : IStrategy
    {
        public void UseAlgorithm()
        {
            Console.WriteLine("Using strategy A");
        }
    }
}
