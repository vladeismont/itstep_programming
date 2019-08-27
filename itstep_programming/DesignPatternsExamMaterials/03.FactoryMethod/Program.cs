using System;
using _03.FactoryMethod.Abstraction;

namespace _03.FactoryMethod
{
    // Factory Method - основа всех порождающих паттернов
    // Определяет интерфейс для создания объекта продукта, оставляя подклассам 
    // возможность самостоятельно принять решение о том, какой класс 
    // продукта следует создать.
    // основные участники: AbstractCreator, ConcreteCreator, AbstractProduct, ConcreteProduct
    internal class Program
    {
        private static void Main()
        {
            AbstractCreator creator = new ConcreteCreator();

            AbstractProduct product = creator.Create();

            Console.WriteLine(product.Description);

            Console.ReadKey();
        }
    }
}
