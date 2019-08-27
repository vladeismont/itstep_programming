using System;
using _09.Strategy.Implementation;

namespace _09.Strategy
{
    internal class Program
    {
        /// <summary>
        /// Паттерн Strategy (Стратегия) определяет набор алгоритмов,
        /// инкапсулируя каждый из них в отдельный класс и делает
        /// их подменяемыми, что позволяет подменять алгоритмы
        /// без участия клиентов
        /// </summary>
        private static void Main()
        {
            var context = new Context(new StrategyA());
            context.Run();
            context = new Context(new StrategyB());
            context.Run();

            Console.ReadKey();
        }
    }
}
