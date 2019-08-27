using System.Collections;
using _11.Visitor.Abstraction;

namespace _11.Visitor.Implementation
{
    class ObjectStructure
    {
        private readonly ArrayList _elements = new ArrayList();

        public void Add(IElement element)
        {
            _elements.Add(element);
        }

        public void Remove(IElement element)
        {
            _elements.Remove(element);
        }

        public void Accept(IVisitor visitor)
        {
            foreach (IElement element in _elements)
            {
                element.Accept(visitor);
            }
        }
    }
}
