using System;
using _01.Bridge.Implementation;

namespace _01.Bridge
{
    // Задача паттерна Bridge - отделение абстракции от реализации, 
    // чтобы их можно было использовать независимо друг от друга
    class Program
    {
        static void Main(string[] args)
        {
            var reader = new TxtFileDataReader();
            var transformer = new TxtLineTransformer();

            var parser = new Parser(reader, transformer);

            var dataItems = parser.ParseFile("data.txt");

            foreach (var dataItem in dataItems)
            {
                Console.WriteLine($"Name: {dataItem.Name}, Org: {dataItem.Organisation}");
            }

            Console.ReadKey();
        }
    }
}
