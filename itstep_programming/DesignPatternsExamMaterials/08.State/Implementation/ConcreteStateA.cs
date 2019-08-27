using System;
using _08.State.Abstraction;

namespace _08.State.Implementation
{
    class ConcreteStateA : IState
    {
        public void Handle(Context context)
        {
            context.State = new ConcreteStateB();
        }
    }
}
