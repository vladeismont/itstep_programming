using System;

namespace _02.Builder.HouseParts
{
    internal class Store
    {
        public Store()
        {
            Console.WriteLine($"Building {nameof(Store)}");
        }

        public override string ToString()
            => nameof(Store);
    }
}