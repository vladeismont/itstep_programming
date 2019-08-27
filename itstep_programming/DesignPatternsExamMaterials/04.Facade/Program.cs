using System;

namespace _04.Facade
{
    // Паттерн Facade предоставляет высокоуровневый доступ к системе, состоящей из нескольких сложных подсистем
    class Program
    {
        static void Main(string[] args)
        {
            var facade = new Facade();

            facade.MakeComplexWork();

            Console.ReadKey();
        }
    }
}
