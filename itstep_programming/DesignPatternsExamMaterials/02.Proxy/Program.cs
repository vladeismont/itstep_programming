using System;

namespace _02.Proxy
{
    /// <summary>
    /// Паттерн Proxy (заместитель) предоставляет объект-заместитель
    /// Пример использования - метод CreateChannel на ChannelFactory в WCF. Полученный Channel - и есть заместитель
    /// Пример использования - комбинация Proxy вместе с техникой Lazy Loading
    /// </summary>
    class Program
    {
        static void Main(string[] args)
        {
            ISubject subject = new Subject();
            subject.Request();
            subject = new Proxy();
            subject.Request();

            Console.ReadKey();
        }
    }
}
