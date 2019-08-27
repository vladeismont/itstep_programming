using System;

namespace _07.Observer.PullModel
{
    class ConcreteObserver : IObserver
    {
        private readonly ConcreteSubject _subject;
        private string _state;

        public ConcreteObserver(ConcreteSubject subject)
        {
            _subject = subject;
        }

        public void Update()
        {
            _state = _subject.State;
            Console.WriteLine($"State of subject {GetHashCode()} updated to \"{_state}\"");
        }
    }
}
