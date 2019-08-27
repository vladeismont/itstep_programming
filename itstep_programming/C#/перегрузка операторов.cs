using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace oerators4
{
    class UserU
    {
        public int data;
        public static UserU operator +(UserU a, UserU b)// перегрузка Ђ+ї
        {
         UserU ob=new UserU();
         ob.data=a.data+b.data;
            return ob;
        }
        public static bool operator ==(UserU a, UserU b)// перегрузка Ђ==ї
        {
            if (a.data == b.data)
                return true;
            else
                return false;
                   }
        public static bool operator !=(UserU a, UserU b)// перегрузка Ђ!=ї
        {
            if (a.data != b.data)
                return false;
            else
                return true;
        }

        public static UserU operator ++(UserU a) // перегрузка Ђ++ї
        {
            a.data++;
            return a;
        }
        // явное преобразование типа UserU к string
        public static explicit operator string(UserU obj)
        {
            return "»нформаци€ о пользователе: " + obj.data+ " лет)";
        }

    }
}
