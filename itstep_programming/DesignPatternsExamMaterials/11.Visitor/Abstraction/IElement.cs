namespace _11.Visitor.Abstraction
{
    public interface IElement
    {
        void Accept(IVisitor visitor);
    }
}