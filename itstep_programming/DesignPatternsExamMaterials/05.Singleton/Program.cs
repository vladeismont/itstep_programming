using System;

namespace _05.Singleton
{
    /// <summary>
    /// Паттерн Singleton описывает, как организовать код таким образом, чтобы в
    /// системе имелся только ОДИН экземпляр какого-то конкретного класса,
    /// либо любое другое количество экземпляров, определённое заранее.
    /// </summary>
    internal class Program
    {
        private static void Main(string[] args)
        {
            var singletonReference1 = Singleton.Instance;
            var singletonReference2 = Singleton.Instance;
            var singletonReference3 = Singleton.Instance;

            Console.WriteLine(singletonReference1.GetHashCode());
            Console.WriteLine(singletonReference2.GetHashCode());
            Console.WriteLine(singletonReference3.GetHashCode());

            Console.ReadKey();
        }
    }
}
