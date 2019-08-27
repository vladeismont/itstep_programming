using System;
using _01.AbstractFactory.Abstraction;
using _01.AbstractFactory.Implementation;

namespace _01.AbstractFactory
{
    /// <summary>
    /// Паттерн "Абстрактная фабрика" предназначен 
    /// для порождения семейств взаимосвязанных объектов,
    /// которые будут взаимодействовать между собой
    /// </summary>
    internal class Program
    {
        private static void Main(string[] args)
        {
            IFactory factory = new Factory();
            Client client = new Client(factory);
            client.Run();

            Console.ReadKey();
        }
    }
}
