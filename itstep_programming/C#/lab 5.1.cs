using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/* Реализовать класс для хранения коплексного числа. Выполнить в нем перегрузку всех необходимых операторов для успешной компиляции кода
	    Complex z = new Complex(1, 1);
            Complex z1;
            z1 = z - (z * z * z - 1) / (3 * z * z);
            Console.WriteLine("z1={0}", z1);*/
namespace ConsoleApplication110
{
    class Program
    {
        class Complex
        {
            int x, y;
            Complex() { x = y = 0; }
            public Complex(int _x, int _y)
            {
                x = _x;
                y = _y;
            }
            public static Complex operator *(Complex C1, Complex C2)
            {
                Complex Res = new Complex();
                Res.x = C1.x * C2.x;
                Res.y = C1.y * C2.y;
                return Res;
            }
            public static Complex operator /(Complex C1, Complex C2)
            {
                Complex Res = new Complex();
                Res.x = C1.x / C2.x;
                Res.y = C1.y / C2.y;
                return Res;
            }
            public static Complex operator -(Complex C1, Complex C2)
            {
                Complex Res = new Complex();
                Res.x = C1.x - C2.x;
                Res.y = C1.y - C2.y;
                return Res;
            }
            public static Complex operator *(Complex C1, int i)
            {
                Complex Res = new Complex();
                Res.x = C1.x * i;
                Res.y = C1.y * i;
                return Res;
            }
            public static Complex operator *(int i, Complex C1)
            {
                Complex Res = new Complex();
                Res.x = C1.x * i;
                Res.y = C1.y * i;
                return Res;
            }
            public static Complex operator -(Complex C1, int i)
            {
                Complex Res = new Complex();
                Res.x = C1.x - i;
                Res.y = C1.y - i;
                return Res;
            }
            public override string ToString()
            {
                /*string x = this.x.ToString();
                string y = this.y.ToString();
                return "(" + x + "," + y + ")";*/
                return string.Format("({0},{1})", x, y);
            }
            public void printcomplex()
            {
                Console.WriteLine(string.Format("комплексное число числа ({0},{1}) ", this.x, this.y) + string.Format("= ({0},{1})", -y, x));
            }
        }
        static void Main(string[] args)
        {
            Complex z = new Complex(1, 1);
            Complex z1;
            z1 = z - (z * z * z - 1) / (3 * z * z);
            Console.WriteLine("z1={0}", z1);
            z1.printcomplex();
            Complex t = new Complex(49, 37);
            t.printcomplex();
            z1 = t - (t * t * t - 1) / (3 * t * t);
            z1.printcomplex();
        }
    }
}
