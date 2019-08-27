using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            UserElement u1 = new UserElement("Травкин");
            UserElement u2 = new UserElement("Майский");
            UserElement u3 = new UserElement("Зямин");
            MyList<UserElement> li = new MyList<UserElement>(u1);
            li.AddElement(u2);
            li.AddElement(u3);
            foreach (var x in li) {
                Console.WriteLine(x.toString());
            
            }

        }
    }
}
