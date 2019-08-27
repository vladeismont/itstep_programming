using System;

namespace _03.Decorator.Implementation
{
    class ConcreteDecoratorA : Abstraction.Decorator
    {
        private string _addedState = nameof(_addedState);

        public override void Operation()
        {
            base.Operation();
            Console.WriteLine(_addedState);
        }
    }
}