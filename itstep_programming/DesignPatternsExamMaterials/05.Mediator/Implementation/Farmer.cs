using System;
using _05.Mediator.Abstraction;

namespace _05.Mediator.Implementation
{
    class Farmer : Colleague
    {
        public Farmer(IMediator mediator) : base(mediator)
        {
        }

        public void GrowBanana()
        {
            var banana = "banana";
            Console.WriteLine($"Farmer raised {banana}");
            Mediator.Send(banana, this);
        }
    }
}
