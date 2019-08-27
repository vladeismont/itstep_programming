using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Calculator calc = new Calculator();
            calc.Add(2, 3);
            Console.WriteLine(DateTime.Now);
            dynamic d;
            int i = 20;
            d = (dynamic)i;
            Console.WriteLine(d);
            System.Console.WriteLine(i.GetType());
            System.Console.WriteLine(d.GetType());
            var stroka = "Hell to World";
            var c = 20;

            Console.WriteLine(c.GetType().ToString());
            Console.WriteLine(stroka.GetType().ToString());
            decimal dec = 7.98845m;
            Console.WriteLine((int)dec);
            Console.ReadLine();
        }
    }

    // объявление нового класса
    class Calculator
    {
        public void Add(int x, int y)
        {
            int z = x + y;
            Console.WriteLine("Сумма {0} и {1} равна {2}", x, y, z);
            
            //либо   если нет Console.ReadLine(); , то  Ctrl+F5

        }
    }
}
