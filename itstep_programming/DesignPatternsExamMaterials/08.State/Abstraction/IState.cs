using _08.State.Implementation;

namespace _08.State.Abstraction
{
    interface IState
    {
        void Handle(Context context);
    }
}