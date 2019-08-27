namespace _02.Command.Implementation
{
    class Invoker
    {
        private Abstraction.Command _command;

        public void StoreCommand(Abstraction.Command command)
        {
            _command = command;
        }

        public void ExecuteCommand()
        {
            _command.Execute();
        }
    }
}
