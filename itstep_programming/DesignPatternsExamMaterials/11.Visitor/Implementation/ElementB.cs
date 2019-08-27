using System;
using _11.Visitor.Abstraction;

namespace _11.Visitor.Implementation
{
    public class ElementB : IElement
    {
        public void Accept(IVisitor visitor)
        {
            visitor.VisitElementB(this);
        }

        public void OperationB()
        {
            Console.WriteLine(nameof(OperationB));
        }
    }
}