using _11.Visitor.Abstraction;

namespace _11.Visitor.Implementation
{
    class Visitor2 : IVisitor
    {
        public void VisitElementA(ElementA elementA)
        {
            elementA.OperationA();
        }

        public void VisitElementB(ElementB elementB)
        {
            elementB.OperationB();
        }
    }
}