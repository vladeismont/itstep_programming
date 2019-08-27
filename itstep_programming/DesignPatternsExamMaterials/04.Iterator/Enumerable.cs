using System;
using System.Collections;

namespace _04.Iterator
{
    class Enumerable : IEnumerable // ConcreteAggregate (IEnumerable == Aggregate)
    {
        private readonly ArrayList _items = new ArrayList();

        public object this[int index]
        {
            get { return _items[index]; }
            set { _items.Insert(index, value); }
        }

        public int Count => _items.Count;

        public IEnumerator GetEnumerator()
        {
            return new Enumerator(this);
        }
    }
}
