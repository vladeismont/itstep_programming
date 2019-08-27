using System;
using _08.State.Abstraction;

namespace _08.State.Implementation
{
    class Context
    {
        public IState State { get; set; }

        public Context(IState state)
        {
            State = state;
        }

        public void Request()
        {
            Console.WriteLine("Context.Request()");
            State.Handle(this);
        }
    }
}
