using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication20
{
    class ContainerClass
    {
        MyElem start;
        MyElem tempv;
        public ContainerClass() {

            start = new MyElem("ауди", 2010);
            start.next = new MyElem("VW", 1996);
            start.next.next = new MyElem("Рено", 1450); 
                }

        public void getInfo() {
            tempv = start;
            for (int i = 0; i < 3; i++) {
                Console.WriteLine(tempv.color + " " + tempv.massa);
                tempv = tempv.next;
            
            }

        
        
        } 

    }
}
