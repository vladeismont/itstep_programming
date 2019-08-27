using _08.State.Abstraction;

namespace _08.State.Implementation
{
    class ConcreteStateB : IState
    {
        public void Handle(Context context)
        {
            context.State = new ConcreteStateA();
        }
    }
}