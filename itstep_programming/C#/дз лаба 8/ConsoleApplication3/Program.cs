using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    public delegate void MyEvent(int x);
    public delegate void MyEvent1();
    class Program
    {
        static void Main(string[] args)
        {
            Employee obj = new Employee();
            obj.Fio = "Иванов";
            obj.Position = "администратор";
            obj.AddSum(200);
            obj.ev +=obj.objwritesn9tiesoscheta;
            obj.ev1 += obj.objwritenedostato4nodenegnaschete;
            Console.WriteLine("сколько хотите снять со счета?");
            int x;
            do
            {
                bool result = int.TryParse(Console.ReadLine(), out x);
                if (result)
                {
                    if (obj.check(x))
                        obj.Withdraw(x);
                    //Console.WriteLine(obj._sum);
                }
                else
                {
                    Console.WriteLine("Attempted conversion of  failed.");
                    break;
                }
            } while (x!=0);

            Console.ReadKey();
        }
    }
}
