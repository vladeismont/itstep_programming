using System;
using _11.Visitor.Implementation;

namespace _11.Visitor
{
    /// <summary>
    /// Паттерн Visitor (посетитель) позволяет единообразно
    /// обойти набор элементов с разными интерфейсами,
    /// а также добавить метод в класс объекта, 
    /// не изменяя сам класс объекта
    /// </summary>
    internal class Program
    {
        private static void Main()
        {
            var structure = new ObjectStructure();

            structure.Add(new ElementA());
            structure.Add(new ElementB());

            structure.Accept(new Visitor1());
            structure.Accept(new Visitor2());

            Console.ReadKey();
        }
    }
}
