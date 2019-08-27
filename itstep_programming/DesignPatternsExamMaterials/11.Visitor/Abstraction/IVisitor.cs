using System.Linq.Expressions;
using _11.Visitor.Implementation;

namespace _11.Visitor.Abstraction
{
    public interface IVisitor
    {
        void VisitElementA(ElementA elementA);

        void VisitElementB(ElementB elementB);
    }
}