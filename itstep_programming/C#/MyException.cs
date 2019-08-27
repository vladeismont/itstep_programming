using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace oerators4
{

    namespace test
    {
        [Serializable]
        class MyException : ApplicationException
        {
            public MyException() { }
            public MyException(string message) : base(message) { }
        }
    }
}
