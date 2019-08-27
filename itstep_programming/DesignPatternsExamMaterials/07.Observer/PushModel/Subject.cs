using System.Collections.Generic;

namespace _07.Observer.PushModel
{
    class Subject
    {
        private readonly IList<IObserver> _observers = new List<IObserver>();

        public void Attach(IObserver observer)
        {
            _observers.Add(observer);
        }

        public void Detach(IObserver observer)
        {
            _observers.Remove(observer);
        }

        public void Notify()
        {
            foreach (var observer in _observers)
            {
                observer.Update(State);
            }
        }

        public string State { get; set; }
    }
}
