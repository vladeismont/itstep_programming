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
            Console.BackgroundColor = ConsoleColor.DarkRed;
            Console.ForegroundColor = ConsoleColor.DarkYellow;
            System.Console.WriteLine("aorkngarjibg");
            double d, n, m;
            d = m = n = double.Parse(Console.ReadLine());
            m = n * n * n * n * n;
            m *= n * n * n * n * n;
            m *= n * n * n * n * n;
            m *= n * n * n * n;
            m = m * n;
            m = m * n;
            Console.WriteLine(m);
            d = Math.Pow(n, 21);
            Console.WriteLine(d);

            System.Console.WriteLine("введите целое число:");
            int i, i1, j, k = 0, f = 0;
            i1 = i = int.Parse(Console.ReadLine());
            while (i % 10 != 0)
            {
                j = i % 10;
                i = i / 10;
                k = k * 10 + j;
                f++;
            }
            var y = 9.3F;
            Random up = new Random();
            double dd=up.NextDouble();
            Console.WriteLine(dd);
            Console.WriteLine(y.GetType());

            // if (f == 0) System.Console.WriteLine("число полиндром"); 
            Console.WriteLine(k);
            System.Console.ReadKey();
            //Convert.ToDouble(Console.Read());
        }
    }
}
