using System;

namespace _04.Prototype
{
    // Prototype описывает технику КЛОНИРОВАНИЯ объектов
    // Основные участники: Prototype, ConcretePrototype
    internal class Program
    {
        private static void Main()
        {
            Prototype originalInstance;
            Prototype clonedInstance;

            originalInstance = new ConcretePrototype(1);
            clonedInstance = originalInstance.Clone();

            Console.WriteLine($"Original instance id = {originalInstance.Id}");
            Console.WriteLine($"Cloned instance id = {clonedInstance.Id}");

            Console.ReadKey();
        }
    }
}
