using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _03.Decorator.Abstraction;

namespace _03.Decorator.Implementation
{
    class ConcreteComponent : Component
    {
        public override void Operation()
        {
            Console.WriteLine("Concrete component operation");
        }
    }
}
