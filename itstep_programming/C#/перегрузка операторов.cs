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
        public static UserU operator +(UserU a, UserU b)// ���������� �+�
        {
         UserU ob=new UserU();
         ob.data=a.data+b.data;
            return ob;
        }
        public static bool operator ==(UserU a, UserU b)// ���������� �==�
        {
            if (a.data == b.data)
                return true;
            else
                return false;
                   }
        public static bool operator !=(UserU a, UserU b)// ���������� �!=�
        {
            if (a.data != b.data)
                return false;
            else
                return true;
        }

        public static UserU operator ++(UserU a) // ���������� �++�
        {
            a.data++;
            return a;
        }
        // ����� �������������� ���� UserU � string
        public static explicit operator string(UserU obj)
        {
            return "���������� � ������������: " + obj.data+ " ���)";
        }

    }
}
