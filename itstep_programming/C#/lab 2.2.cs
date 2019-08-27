using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*9.	Напишите программу для вычисления среднего арифмитического элементов всех четных столбцов рваного массива.  */
namespace ArrayFunctions
{
    class Program
    {
        static void Main(string[] args)
        {
            int size=5,line;
            int[][] arr = new int[size][];
            Random rand = new Random();
            for (int i = 0; i < size; i++)
            {
                line=rand.Next(1,9);
                arr[i] = new int[line];
                for (int j = 0; j < line; j++)
                {
                    arr[i][j] = rand.Next(1, 99);
                    Console.Write("{0}\t", arr[i][j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine("_______________________________________________________");
            double Sum=0,f=0;
            for (int i = 0; i < arr.Length; i++)
            {
                int z = 0;
                foreach (int j in arr[i])
                {
                    f++;
                    z++;
                    if (z % 2 == 0 ) Sum += j;
                    Console.Write("{0}\t",j);
                }
                Console.WriteLine();
            }
            Console.WriteLine(f);
            Console.WriteLine(Sum);
            Console.WriteLine("_______________________________________________________");
            Console.WriteLine("среднее арифмитическое элементов всех четных столбцов рваного массива =\n" + Sum / f);
            Console.WriteLine("_______________________________________________________");

        }
    }
}
