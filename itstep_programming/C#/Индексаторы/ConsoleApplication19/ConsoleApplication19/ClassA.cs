using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication19
{
    class ClassA
    {
        string[] ar = new string[3];
           string[] ar2 = new string[3];
      /*  public int this[int index]{
            get {

                return ar[index];
            }
            set {
                ar[index] = value;
            }
        
        }*/
        public string[] Ar2{
        get{
        return ar2;
        }
        }
        public string this[string str]
        {
            get
            {

                for(int ){
                    
                if(ar2.Contains(str)){
               return 
                }
                return ar2[str];
            }
            set
            {
                ar2[Convert.ToInt16(str)] = value;
            }

        }


    }
}
