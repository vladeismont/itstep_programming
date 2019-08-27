using _05.Mediator.Abstraction;

namespace _05.Mediator.Implementation
{
    class SalesMediator : IMediator
    {
        public Farmer Farmer { get; set; }
        public Shop Shop { get; set; }

        public void Send(string message, Colleague colleague)
        {
            if (colleague == Farmer)
            {
                Shop.SellBanana(message);
            }
        }
    }
}
