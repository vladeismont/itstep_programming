using System;
using _08.State.Implementation;

namespace _08.State
{
    internal class Program
    {
        /// <summary>
        /// Паттерн State позволяет объекту изменять своё поведение 
        /// в зависимочти от своего состояния
        /// </summary>
        private static void Main()
        {
            var context = new Context(new ConcreteStateA());
            Console.WriteLine($"Current state of context is: {context.State.GetType().Name}");

            context.Request();
            Console.WriteLine($"Current state of context is: {context.State.GetType().Name}");

            context.Request();
            Console.WriteLine($"Current state of context is: {context.State.GetType().Name}");

            context.Request();
            Console.WriteLine($"Current state of context is: {context.State.GetType().Name}");

            Console.ReadKey();
        }
    }
}
