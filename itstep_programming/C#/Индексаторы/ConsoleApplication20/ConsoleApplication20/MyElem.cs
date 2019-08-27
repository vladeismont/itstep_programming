using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication20
{
    class MyElem
    {
        public string color;
        public int massa;
        public MyElem(string color, int massa) {
            this.color = color;
            this.massa = massa;

            next = null;     
        }
        public MyElem next;

    }
}
