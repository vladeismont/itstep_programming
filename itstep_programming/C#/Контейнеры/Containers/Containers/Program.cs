using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Containers
{
    class Program
    {
        static void Main(string[] args)
        {
           
            
           /*LinkedList<UserU> li = new LinkedList<UserU>();
            li.AddLast(new UserU(56, "Яшин"));
            li.AddLast(new UserU(5,"Зямин"));
            li.AddLast(new UserU(3, "Зямин"));
            li.AddLast(new UserU(4, "Яшин"));
            IOrderedEnumerable<UserU> li2 = li.OrderBy(i => i.fio).OrderBy(i=>i.id);
            foreach (var x in li2) {
                Console.WriteLine(x);
            
            }*/
            List<UserU> li = new List<UserU>();
            li.Add(new UserU(56, "Яшин"));
            li.Add(new UserU(5, "Зямин"));
            li.Add(new UserU(3, "Зямин"));
           // li.Sort();
            Comp<UserU> cp = new Comp<UserU>();
            li.Sort(cp);
            foreach (var x in li)
            {
                Console.WriteLine(x);
            }
           /* HashSet<UserU> hst = new HashSet<UserU>();
            UserU u = new UserU(12, "Зямин");
            UserU u1 = new UserU(12, "Зямин");
            hst.Add(new UserU(12, "Зямин"));
            hst.Add(new UserU(12, "Зямин"));
            Console.WriteLine(new UserU(12, "Зямин").GetHashCode());
            Console.WriteLine(new UserU(12, "Зямин").GetHashCode());
            */
            /* Dictionary<string, int> myDi = new Dictionary<string, int>();
            myDi.Add("Дом", 1);
            myDi.Add("Кот", 8);
            myDi["Кот1"] += 2;
            foreach (var v in myDi){
                Console.WriteLine(v.Value);
                     }
            Console.WriteLine(myDi["Кот"]);*/

        }
    }
}
