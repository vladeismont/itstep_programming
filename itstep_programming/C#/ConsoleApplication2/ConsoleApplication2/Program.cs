using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//работа со строками, перегруженные методы, конструктор, методы с необязательными аргументами, и с использованием именованых аргументов, свойства классов, модификаторы доступа, в рамках работы со строками иметь сравнить две строки, выделить подстроку, разбить строку на части по разделителю
namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] A = new int[5];
            int[,] B = new int[3, 4];
            //Random ran = new Random(); ran.Next(1, 15);
            for (int i = 0; i < 5; i++)
            {
                A[i] = int.Parse(Console.ReadLine());
                //sring str=Console.ReadLine();
                //A[i] = Convert.ToInt16(str);
            }
            Random ran = new Random();
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    B[i, j] = ran.Next(1, 8);
                }
            }
            for (int i = 0; i < 5; i++)
            {
                Console.Write(A[i]);
                Console.Write(' ');
            }
            Console.Write("\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    Console.Write(B[i,j]);
                    Console.Write(' ');
                }
                Console.Write("\n");
            }

            int min, max,sum,composition;
            int sumEven, sumUneven;
            sumEven = sumUneven = 0;
            composition=sum=min = max = A[0];
            int f = 0;
            for (int i = 1; i < 5; i++)
            {
                if (min > A[i])
                {
                    min = A[i];
                }
                if (max < A[i])
                {
                    max = A[i];
                }
                sum += A[i];
                composition *= A[i];
                f++;
                if (f % 2 == 1)
                {
                    sumEven += A[i];
                }
            }

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (min > B[i,j])
                    {
                        min = B[i,j];
                    }
                    if (max < B[i,j])
                    {
                        max = B[i,j];
                    }
                    sum += B[i, j];
                    composition *= B[i, j];
                    if ((j + 1) % 2 == 1)
                    {
                        sumUneven += B[i, j];
                    }
                }
            }
            Console.WriteLine("минимальный элемент массива: {0}", min);
            Console.WriteLine("максимальный элемент массива: {0}", max);
            Console.WriteLine("сумма всех элементов массива: {0}", sum);
            Console.WriteLine("общее произведение всех элементов: {0}", composition);
            Console.WriteLine("сумму четных элементов массива А: {0}", sumEven);
            Console.WriteLine("сумму нечетных столбцов массива В: {0}", sumUneven);
            const int M = 5, N = 5;
            int Z = M + N;
            int[] A1 = new int[M];
            int[] A2 = new int[N];
            for (int i = 0; i < M; i++)
            {
                A1[M] = ran.Next(1, 5);
            }
            for (int i = 0; i < N; i++)
            {
                A1[N] = ran.Next(1, 5);
            }
            int[,] A3=new int[Z,2];
            for (int i = 0; i < Z; i++)
            {
                //A3[i, 0] = A1[i];
            }

            int[,] array = new int[5, 5];
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    array[i, j] = ran.Next(-100, 100);
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    
                }
            }
                Console.ReadLine();
        }
    }
}
