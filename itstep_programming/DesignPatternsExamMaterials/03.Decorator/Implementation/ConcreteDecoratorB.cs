using System;

namespace _03.Decorator.Implementation
{
    class ConcreteDecoratorB : Abstraction.Decorator
    {
        private void AddedBehavior()
        {
            Console.WriteLine(nameof(AddedBehavior));
        }

        public override void Operation()
        {
            base.Operation();
            AddedBehavior();
        }
    }
}