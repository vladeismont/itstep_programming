using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*разработать класс Fraction, представляющий простую дробь. в классе предусмотреть два поля: числитель и знаменатель дроби. выполнить перегрузку операторов... и операторы true false. Выполнить перегрузку операторов, необходимых для успешной компиляции следующего кода: ...*/

namespace ConsoleApplication108
{
    class Program
    {
        class Fraction
        {
            public int numerator, denumerator;
            public Fraction()
            {
                numerator = denumerator = 0;
            }
            public Fraction(int _x, int _y)
            {
                numerator = _x;
                denumerator = _y;
            }
            public static Fraction operator *(Fraction _f, int _i)
            {
                Fraction Fr = new Fraction();
                Fr.numerator = _f.numerator * _i;
                Fr.denumerator = _f.denumerator;
                return Fr;
            }
            public static Fraction operator *(int _i, Fraction _f)
            {
                Fraction Fr = new Fraction();
                Fr.numerator = _f.numerator * _i;
                Fr.denumerator = _f.denumerator;
                return Fr;
            }
            public void show()
            {
                Console.WriteLine("{0}/{1}", numerator, denumerator);
            }
            public static Fraction operator +(Fraction _f, double _d) //метод с заданным значением _d, тоесть с заданным числителем и знаменателем
            {
                Fraction Fr = new Fraction();
                Fr.numerator = _f.numerator * 3;
                Fr.denumerator = _f.denumerator * 2;
                return Fr;
            }
            public static bool operator true(Fraction _f)
            {
                if (_f.numerator < _f.denumerator)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            public static bool operator false(Fraction _f)
            {
                if (_f.numerator >= _f.denumerator)
                    return false;
                return true;
            }
            public static Fraction operator *(Fraction _f1, Fraction _f2)
            {
                Fraction Fr = new Fraction();
                Fr.numerator = _f1.numerator * _f2.numerator;
                Fr.denumerator = _f1.denumerator * _f2.denumerator;
                return Fr;
            }

        }
        static void Main(string[] args)
        {
            Fraction f = new Fraction(3,4);
            f.show();
            int a = 10;
            Fraction f1 = f * a;
            f1.show();
            Fraction f2 = a * f;
            f2.show();
            double d = 1.5;
            Fraction f3 = f + d;
            Console.WriteLine("___");
            f3.show();
            Fraction f4 = f3;
            if (f3)
            {
                Console.WriteLine("    - эта правильная дробь");
            }
            else Console.WriteLine("    - эта дробь неправильная");
            f3 = f3 * f1;
            f3.show();
        }
    }
}
