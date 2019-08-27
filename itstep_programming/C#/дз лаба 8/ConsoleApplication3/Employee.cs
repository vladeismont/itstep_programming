using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    
    class Employee: Account
    {
        String fio; // Переменная для хранения фамилии сотрудника
        String position; // Переменная для хранения должности
        
        public string Fio
        {
            get
            {
                return fio;
            }

            set
            {
                fio = value;
            }
        }

        public string Position
        {
            get
            {
                return position;
            }

            set
            {
                position = value;
            }
        }

        public bool check(int sum) {
            if (sum + sum > _sum)
            {
                Random rnd = new Random();
                int x = rnd.Next(0, 2);
                if (x == 1)
                {
                    Console.WriteLine("было принято решение снять со счета");
                    return true;
                }
                else
                {
                    Console.WriteLine("было принято решение не снимать со счета");
                    return false;
                }
            }
            else return true;
        }//метод для утверждения снятия суммы. 
    }
}
