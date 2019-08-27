using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication103
{
    class Program
    {
        static void Main(string[] args)
        {
            // -> example 1
            /*Задание 1. Даны целые положительные числа А и В (A < B). Вывести все целые числа от А до В включительно; каждое число должно выводиться на новой строке; при этом каждое число должно выводиться количество раз, равное его значению (например, число 3 выводится 3 раза)*/
            int A = 1, B = 11;
            for (int i = A + 1; i < B; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    Console.WriteLine(i);
                }
            }
            /*for (int i = 65; i < 91; i++)
            {
                Console.WriteLine((char)i);
            }*/
            Console.WriteLine("_________________________________________________");

            // -> example 2
            /*Вывести следующие строки (количество строк вводится с клавиатуры ):
A B C D E
B C D E F
C D E F G
D E F G H
E F G H I и т.д.
(Использовать тип char).
*/
            Console.WriteLine("Введите количество строк для вывода:");
            char ch = 'A';
            int num;
            while (!int.TryParse(Console.ReadLine(), out num))
            {
                Console.WriteLine("Неверный ввод\nвведите число строк для вывода:");
            }
            //Console.WriteLine(num);
            int f = 0;
            for (int i = 0; i < num; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (ch + j > 90) { f = 1; break; }
                    Console.Write((char)(ch + j) + " ");
                }
                if (f == 1) { Console.WriteLine("\nдостигнут конец!"); break; } // напечатали last Uppercase char англ алфавита и выход
                ch++;
                Console.Write("\n");
            }//написал первое что пришло на ум. 
            //а вот кое-что еще http://www.dotnetperls.com/tostring
            Console.WriteLine("_________________________________________________");

            // -> example 3
            /*Задание 3. Определить, является ли введенное число числом-перевертышем.*/
            int n1, n2, n3, n4 = 0;
            Console.WriteLine("Введите целое положительное число");
            while (!int.TryParse(Console.ReadLine(), out n1))
            {
                Console.WriteLine("неверный ввод");
            }
            n2 = n1;
            while (n2 % 10 != 0 && n1 > 9)
            {
                n3 = n2 % 10;
                n2 = n2 / 10;
                n4 = n4 * 10 + n3;
            }
            if (n4 == n1 && n1 > 9) Console.WriteLine(n1 + "  -являеться числом-перевертышем!");
            else Console.WriteLine(n1 + "  -не являеться числом-перевертышем!");
            Console.WriteLine("_________________________________________________");

            // -> example 4
            /*Задание 4. Проверка на  интервал с дополнительным условием
             интервал 30-300 ; X <905 */
            int x;
            Console.WriteLine("введите Х");
            while (!int.TryParse(Console.ReadLine(), out x))
            {
                Console.WriteLine("неверный ввод");
            }
            if (x < 905)
            {
                if (x < 300 && x > 30) Console.WriteLine(x + " меньше 905, а также размещен в интервале 30-300");
                else Console.WriteLine(x + " меньше 905, но не размещен в интервале 30-300");
            }
            else Console.WriteLine(x + " не размещен в интервале 30-300");
            Console.WriteLine("_________________________________________________");

            // -> example 5
            /*Оператор switch. Проверка на попадание в список значений.
             значения 331,337,339,425 */
            Console.WriteLine("загаданы четыре числа. попробуйте угадайте одно из них");
            int y;
            while (!int.TryParse(Console.ReadLine(), out y))
            {
                Console.WriteLine("неверный ввод\nПопробуйте снова");
            }
            switch (y)
            {
                case 331: Console.WriteLine("число 331 угадано!"); break;
                case 337: Console.WriteLine("число 337 угадано!"); break;
                case 339: Console.WriteLine("число 339 угадано!"); break;
                case 425: Console.WriteLine("число 425 угадано!"); break;
                default: Console.WriteLine("вы не угадали"); break;
            }
            Console.WriteLine("_________________________________________________");

            // -> example 6
            /*Задание 6. Операторы циклов (использовать  операторы while, do-while и for )
            Вывести значение выражения X*X-5*X в интервале -3..3   */
            double X = -3, result;
            double k = 6.0 / 21;
            X = X + k;
            Console.WriteLine(k + "     " + X);
            while (X < 3 - k)
            {
                result = X * X - 5 * X;
                Console.WriteLine(X + "   " + result);
                X = X + k;
            }
            Console.WriteLine("_________________________________________________");

            // -> example 7
            // Определить сумму наименьшей и наибольшей цифры в числе
            int Y, Ymin = 9, Ymax = 0;
            Console.WriteLine("введите число");
            while (!int.TryParse(Console.ReadLine(), out Y))
            {
                Console.WriteLine("неверный ввод\nПопробуйте снова");
            }
            while (Y > 0)
            {
                if (Ymin > Y % 10) Ymin = Y % 10;
                if (Ymax < Y % 10) Ymax = Y % 10;
                Y = Y / 10;
            }
            Console.WriteLine("сумма= " + (Ymin + Ymax));
            Console.WriteLine("_________________________________________________");

            // -> example 8
            //Рассчитать сумму чисел 100 Фибоначчи : 1, 1, 2, 3, 5, 8 ..   Xn=X(n-1)+X(n-2)
            long Xn=1, Xn1=0, Xn2=1, Xnext;
            for (int i = 0; i < 100; i++)
            {
                Xn += Xn1 + Xn2;
                Xnext = Xn1 + Xn2;
                Xn1 = Xn2;
                Xn2 = Xnext;
            }
            Console.WriteLine("сумма 100 цифр Фибоначчи= "+Xn);
        }
    }
}
