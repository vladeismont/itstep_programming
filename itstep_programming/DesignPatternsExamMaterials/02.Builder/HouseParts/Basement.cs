using System;

namespace _02.Builder.HouseParts
{
    internal class Basement
    {
        public Basement()
        {
            Console.WriteLine($"Building {nameof(Basement)}");
        }

        public override string ToString()
            => nameof(Basement);
    }
}