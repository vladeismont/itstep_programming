namespace _05.Mediator.Abstraction
{
    abstract class Colleague
    {
        protected IMediator Mediator;

        protected Colleague(IMediator mediator)
        {
            Mediator = mediator;
        }
    }
}