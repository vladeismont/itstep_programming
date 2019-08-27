using System;
using _01.ChainOfResponsibility.Abstraction;

namespace _01.ChainOfResponsibility.Implementation
{
    class ConcreteHandler1 : Handler
    {
        // реализация метода обработки запроса
        public override void HandleRequest(int request)
        {
            // Если способен обработать запрос - обрабатываем его
            if (request == 1)
                Console.WriteLine("One");
            // если не способен обработать запрос - передаём запрос преемнику
            else
                Successor?.HandleRequest(request);
        }
    }
}
