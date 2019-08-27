using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Containers
{
    class Comp<T>: IComparer<T> where T:UserU
    {
        public int Compare(T x, T y)
        {
            if (x.id > y.id)
                return 1;
            else if (x.id == y.id)
                return 0;
            else return -1;

        }
    }
}
