namespace _05.Flyweight
{
    class FlyweightWrapperB : Flyweight
    {
        private readonly Flyweight _flyweight;

        public FlyweightWrapperB(Flyweight flyweight)
        {
            _flyweight = flyweight;
        }

        public override void Say(string message)
        {
            this._flyweight.Say(message);
        }
    }
}