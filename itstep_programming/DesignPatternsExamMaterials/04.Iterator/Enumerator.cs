using System.Collections;

namespace _04.Iterator
{
    class Enumerator : IEnumerator // ConcreteIterator (IEnumerator == Iterator)
    {
        private readonly Enumerable _enumerable;
        private int _current;

        public Enumerator(Enumerable enumerable)
        {
            _enumerable = enumerable;
            _current = -1;
        }

        public bool MoveNext()
        {
            if (_current < _enumerable.Count - 1)
            {
                _current++;
                return true;
            }
            return false;
        }

        public void Reset()
        {
            _current = -1;
        }

        public object Current => _enumerable[_current];
    }
}
