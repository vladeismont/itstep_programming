using System;

namespace _02.Builder
{
    // Отделение пошагового конструирования сложного объекта (продукта) от его представления
    // Паттерн Builder предназначен для пошагового построения сложных продуктов
    // В результате одного и того же процесса конструирования конечный результат зависит от конкретной реализация класса Builder.
    // Основные участники: Director, AbstractBuilder, ConcreteBuilder, Product
    internal class Program
    {
        private static void Main()
        {
            Builder builder = new ConcreteBuilder();
            Foreman foreman = new Foreman(builder);
            foreman.Construct();

            House house = builder.GetResult();

            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine(house);

            Console.ReadKey();
        }
    }
}
