using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication4
{
    class Palindrom
    {
        /*public static bool Palindromtest(string s)
        {
            for (int i = 1, j = s.Length - 1; i < j; i++, j--)

                if (s[i] != s[j])
                    return false;
            return true;
        }*/
        public static bool Palindrom(string s)
        {
            for (int i = 0; i < s.Length / 2; i++)

                if (s[i] != s[s.Length - i - 1])
                    return false;
            return true;
        }
    }
}
