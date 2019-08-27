namespace _05.Flyweight
{
    class FlyweightWrapperA : Flyweight
    {
        private readonly Flyweight _flyweight;

        public FlyweightWrapperA(Flyweight flyweight)
        {
            _flyweight = flyweight;
        }

        public override void Say(string message)
        {
            this._flyweight.Say(message);
        }
    }
}