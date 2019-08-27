using System;

namespace _05.Flyweight
{
    /// <summary>
    /// Паттерн Flyweight предназначен для организации работы с разделяемыми объектами
    /// </summary>
    class Program
    {
        static void Main(string[] args)
        {
            // разделяемый объект
            Flyweight instance = new FlyweightImplementation();
            instance.Say("Say from original instance");

            // неразделяемый объект 1
            Flyweight wrapper1 = new FlyweightWrapperA(instance);
            instance.Say("Say from wrapper1");

            // неразделяемый объект 2
            Flyweight wrapper2 = new FlyweightWrapperB(instance);
            instance.Say("Say from wrapper2");

            Console.ReadKey();
        }
    }
}
