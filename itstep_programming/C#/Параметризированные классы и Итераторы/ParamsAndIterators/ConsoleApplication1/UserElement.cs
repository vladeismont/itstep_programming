using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class UserElement:IElems<UserElement>
    {
        string fio;
        public UserElement(string fio) {
            this.fio = fio;
                    }


        public string toString()
        {
            return fio;
        }

        public UserElement Next
        {
            get;
            set;
        }
    }
}
