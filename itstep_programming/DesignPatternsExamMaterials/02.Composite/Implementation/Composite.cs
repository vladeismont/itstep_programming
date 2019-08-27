using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _02.Composite.Abstraction;

namespace _02.Composite.Implementation
{
    class Composite : Component
    {
        private readonly IList<Component> _children = new List<Component>();

        public Composite(string name) : base(name)
        {
        }

        public override void Operation()
        {
            Console.WriteLine(Name);

            foreach (var child in _children)
                child.Operation();
        }

        public override void Add(Component item)
        {
            _children.Add(item);
        }

        public override void Remove(Component item)
        {
            _children.Remove(item);
        }

        public override Component GetChild(int index)
        {
            return _children[index];
        }
    }
}
