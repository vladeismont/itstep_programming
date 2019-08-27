using System;

namespace _04.Iterator
{
    internal class Program
    {
        /// <summary>
        /// Паттерн Iterator (Итератор) предоставляет удобный и безопасный 
        /// интерфейс доступа к коллекции или любому другому составному объекту, 
        /// не раскрывая самой реализации коллекции
        /// в .NET представлен интерфейсами IEnumerable (интерфейс коллекции или составного объекта) 
        /// и IEnumerator (Интерфейс самого итератора, предоставляющего доступ к элементам коллекции)
        /// Для использования foreach, объект должен иметь открытый метод с сигнатурой GetEnumerator()
        /// </summary>
        private static void Main()
        {
            var enumerable = new Enumerable
            {
                [0] = "Zero",
                [1] = "One",
                [2] = "Two",
                [3] = "Three",
                [4] = "Four"
            };


            foreach (var item in enumerable)
            {
                Console.WriteLine(item);
            }

            Console.ReadKey();
        }
    }
}
