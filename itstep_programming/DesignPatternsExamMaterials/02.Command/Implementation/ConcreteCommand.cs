namespace _02.Command.Implementation
{
    class ConcreteCommand : Abstraction.Command
    {
        public ConcreteCommand(Reciever reciever) 
            : base(reciever) { }

        public override void Execute()
        {
            Reciever.Action();
        }
    }
}