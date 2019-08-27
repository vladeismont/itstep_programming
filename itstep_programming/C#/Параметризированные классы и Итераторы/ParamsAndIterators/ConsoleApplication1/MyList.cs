using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class MyList<T> where T : class, IElems<T>
    {
        T head;
        T tail;
        int count;

        public MyList(T tempElem) {
            head = tempElem;
            tail = tempElem;
            count = 1;
                }
        public void AddElement(T tempElem) {
            tail.Next = tempElem;
            tail = tempElem;
            count++;
           }
        public IEnumerator<T> GetEnumerator() {
            T tempElem = head;
           
                yield return head;

                if (count > 1)
                {
                    for (int i = 0; i < count - 1; i++)
                    { tempElem = tempElem.Next;
                     yield return tempElem;
                       
                    }
                }
        
        }

    }
}
