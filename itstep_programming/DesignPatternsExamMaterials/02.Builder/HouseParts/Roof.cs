using System;

namespace _02.Builder.HouseParts
{
    internal class Roof
    {
        public Roof()
        {
            Console.WriteLine($"Building {nameof(Roof)}");
        }

        public override string ToString()
            => nameof(Roof);
    }
}