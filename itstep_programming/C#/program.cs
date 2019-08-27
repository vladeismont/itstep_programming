using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using oerators4.test;

namespace oerators4
{
    class Program
    {
        static void input() {

            Exception exc = new Exception();
            exc.HelpLink = "http://www.exception.ru";

            exc.Data.Add("Время возникновения: ", DateTime.Now);
            exc.Data.Add("Причина: ", "Некорректное значение");
            throw exc;

            
            try
            {
                Console.WriteLine("Введите число");
                int data = Convert.ToInt16(Console.ReadLine());
                MyException exx=new MyException("Что-то сломалось");
                exx.Data.Add("Компьютер:", "локальный" );
                exx.Data.Add("Время:", DateTime.Now);
                
                throw exx;
            }
            catch (MyException e)
            {
                foreach (DictionaryEntry d in e.Data)
                    Console.WriteLine("-> {0} {1}", d.Key, d.Value);
                Console.WriteLine("\n\n");
            }
        }

        static void Main(string[] args)
        {
            input();

            UserU u1 = new UserU();
            u1.data = 10;
            UserU u2 = new UserU();
            u2.data = 10;
            UserU u3;
         
            Console.Read();

        }
    }
}
