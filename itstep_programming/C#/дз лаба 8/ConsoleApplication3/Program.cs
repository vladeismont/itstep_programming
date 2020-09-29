using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Program
    {
        public delegate string MyDel(string str);
        class A
        {
            protected event MyDel myEvent;
            public A()
            {
                this.myEvent += new MyDel(this.welcomeUser);
            }

            private string welcomeUser(string str)
            {
                return str;
            }

            static void Main(string[] args)
            {
                A a1 = new A();
                //string result = a1.myEvent(" event\n");
                Action Notifyln = delegate { Console.Write("hello delegate\n"); Console.Write(a1.myEvent(" and hello class A event\n")); };
                Notifyln?.Invoke();
                

                Account acc = new Account(100);
                acc.Notify += DisplayMessage;   // Добавляем обработчик для события Notify
                acc.Put(20);    // добавляем на счет 20
                Console.WriteLine($"Сумма на счете: {acc.Sum}");
                acc.Take(70);   // пытаемся снять со счета 70
                Console.WriteLine($"Сумма на счете: {acc.Sum}");
                acc.Take(180);  // пытаемся снять со счета 180
                Console.WriteLine($"Сумма на счете: {acc.Sum}");
                Console.Read();
            }
        }
        private static void DisplayMessage(string message)
        {
            Console.WriteLine(message);
        }
    }
}
