using System;

namespace _05.Flyweight
{
    class FlyweightImplementation : Flyweight
    {
        public override void Say(string message)
        {
            Console.WriteLine(message);
        }
    }
}