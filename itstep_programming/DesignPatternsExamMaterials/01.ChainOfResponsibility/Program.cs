using System;
using _01.ChainOfResponsibility.Abstraction;
using _01.ChainOfResponsibility.Implementation;

namespace _01.ChainOfResponsibility
{
    /// <summary>
    /// Паттерн Chain of Responsibility (Цепочка обязанностей) позволяет 
    /// избежать привязки объекта-отправителя запроса к объекту-получателю запроса,
    /// связывая обработчики в "цепочку" и передавая запросы по ней
    /// </summary>
    internal class Program
    {
        private static void Main()
        {
            Handler h1 = new ConcreteHandler1();
            Handler h2 = new ConcreteHandler2();

            h1.Successor = h2;

            h1.HandleRequest(1);
            h1.HandleRequest(2);
            
            Console.ReadKey();
        }
    }
}
