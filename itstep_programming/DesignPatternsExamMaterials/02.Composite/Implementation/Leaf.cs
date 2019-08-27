using System;
using _02.Composite.Abstraction;

namespace _02.Composite.Implementation
{
    class Leaf : Component
    {
        public Leaf(string name) : base(name)
        {
        }

        public override void Operation()
        {
            Console.WriteLine(Name);
        }

        public override void Add(Component item)
        {
            throw new NotImplementedException();
        }

        public override void Remove(Component item)
        {
            throw new NotImplementedException();
        }

        public override Component GetChild(int index)
        {
            throw new NotImplementedException();
        }
    }
}
