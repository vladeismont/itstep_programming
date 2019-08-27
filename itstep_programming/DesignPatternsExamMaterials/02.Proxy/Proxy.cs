using System;

namespace _02.Proxy
{
    class Proxy : ISubject
    {
        private Subject _subject;

        public void Request()
        {
            Console.WriteLine("Requesting by proxy");

            if (_subject == null)
            {
                _subject = new Subject();
            }

            _subject.Request();
        }
    }
}
