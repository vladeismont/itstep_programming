namespace _05.Mediator.Abstraction
{
    interface IMediator
    {
        void Send(string message, Colleague colleague);
    }
}