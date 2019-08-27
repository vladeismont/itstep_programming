using System;

namespace _01.Adapter
{
    class ProviderA : Provider
    {
        public override void Do()
        {
            Console.WriteLine("Using provider A");
        }
    }
}