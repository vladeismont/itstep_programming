using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Account
    {
        public event MyEvent ev;
        public event MyEvent1 ev1;
        protected int _sum; // Переменная для хранения суммы
        public void Withdraw(int sum) {
            if (_sum >= sum)
            {
                ev(sum);
                _sum -= sum;
            }
            else { ev1(); }
        }//  снятие денег со счёта
        public void AddSum(int sum) { _sum += sum; }//  пополнение счёта
        public void objwritesn9tiesoscheta(int x)
        {
            Console.WriteLine("Сумма {0} снята со счета", x);
        }
        public void objwritenedostato4nodenegnaschete()
        {
            Console.WriteLine("Недостаточно денег на счете");
        }
    }
}
