namespace _04.Prototype
{
    internal class ConcretePrototype : Prototype
    {
        public ConcretePrototype(int id) 
            : base(id)
        {
        }

        public override Prototype Clone()
        {
            return new ConcretePrototype(Id);
        }
    }
}