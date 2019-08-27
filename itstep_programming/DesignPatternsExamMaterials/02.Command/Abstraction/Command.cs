using _02.Command.Implementation;

namespace _02.Command.Abstraction
{
    abstract class Command
    {
        protected Reciever Reciever;

        protected Command(Reciever reciever)
        {
            Reciever = reciever;
        }

        public abstract void Execute();
    }
}