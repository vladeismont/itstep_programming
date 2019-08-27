using System;

namespace _02.Proxy
{
    class Subject : ISubject
    {
        public void Request()
        {
            Console.WriteLine("Making request");
        }
    }
}
