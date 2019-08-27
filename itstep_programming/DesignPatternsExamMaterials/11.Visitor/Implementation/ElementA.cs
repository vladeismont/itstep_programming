using System;
using _11.Visitor.Abstraction;

namespace _11.Visitor.Implementation
{
    public class ElementA : IElement
    {
        public void Accept(IVisitor visitor)
        {
            visitor.VisitElementA(this);
        }

        public void OperationA()
        {
            Console.WriteLine(nameof(OperationA));
        }
    }
}
