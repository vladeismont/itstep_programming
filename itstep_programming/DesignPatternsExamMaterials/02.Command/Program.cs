using System;
using _02.Command.Implementation;

namespace _02.Command
{
    /// <summary>
    /// Паттерн Command(Команда) позволяет представить запрос в виде объекта, позволяя клиенту
    /// сконфигурировать запрос, задавая параметры для его обработки, а также ставить запросы в очередь,
    /// протоколировать их и поддерживать отмену операций
    /// </summary>
    internal class Program
    {
        private static void Main()
        {
            Reciever reciever = new Reciever();
            Abstraction.Command command = new ConcreteCommand(reciever);
            Invoker invoker = new Invoker();

            invoker.StoreCommand(command);
            invoker.ExecuteCommand();

            Console.ReadKey();
        }
    }
}
