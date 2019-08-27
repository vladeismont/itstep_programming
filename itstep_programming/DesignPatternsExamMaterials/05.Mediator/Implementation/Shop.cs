using System;
using _05.Mediator.Abstraction;

namespace _05.Mediator.Implementation
{
    class Shop : Colleague
    {
        public Shop(IMediator mediator) : base(mediator)
        {
        }

        public void SellBanana(string message)
        {
            Console.WriteLine($"Shop sold {message}");
        }
    }
}