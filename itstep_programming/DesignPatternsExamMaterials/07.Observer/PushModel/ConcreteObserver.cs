using System;

namespace _07.Observer.PushModel
{
    class ConcreteObserver : IObserver
    {
        private string _state;
        
        public void Update(string state)
        {
            _state = state;
            Console.WriteLine($"State of subject {GetHashCode()} updated to \"{_state}\"");
        }
    }
}
