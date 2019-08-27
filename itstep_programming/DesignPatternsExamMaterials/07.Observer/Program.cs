using System;
using _07.Observer.PushModel;
// using _07.Observer.PullModel;

namespace _07.Observer
{
    /// <summary>
    /// Паттерн Observer описывает технику оповещения 
    /// объектов-подписчиков об изменении состояния 
    /// объекта-издателя
    /// </summary>
    internal class Program
    {
        private static void Main()
        {
            // Pull Model - подписчик самостоятельно забирает информацию от издателя
            // ConcreteSubject subject = new ConcreteSubject();
            // subject.Attach(new ConcreteObserver(subject));
            // subject.Attach(new ConcreteObserver(subject));
            // subject.State = "Current state";
            // subject.Notify();

            // Push Model - издатель самостоятельно передаёт подписчику информацию
            Subject subject = new Subject();
            subject.Attach(new ConcreteObserver());
            subject.Attach(new ConcreteObserver());
            subject.State = "Current state";
            subject.Notify();

            Console.ReadKey();
        }
    }
}
