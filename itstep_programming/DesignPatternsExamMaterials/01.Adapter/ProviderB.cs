using System;

namespace _01.Adapter
{
    class ProviderB : Provider
    {
        public override void Do()
        {
            Console.WriteLine("Using provider B");
        }
    }
}