using _09.Strategy.Abstraction;

namespace _09.Strategy.Implementation
{
    class Context
    {
        private readonly IStrategy _strategy;

        public Context(IStrategy strategy)
        {
            _strategy = strategy;
        }

        public void Run()
        {
            _strategy.UseAlgorithm();
        }
    }
}
