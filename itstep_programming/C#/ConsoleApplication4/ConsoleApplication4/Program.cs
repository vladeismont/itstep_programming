using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            
            string str;
            str = Console.ReadLine();
            //Console.WriteLine(str);
            string[] words = str.Split(' ');
            for (int i = 0; i < words.Length; i++)
            {
                for (int j = 1 + i; j < words.Length; j++)
                {
                    if (Palindrom(words[i])) {
                    
                    }
                }
                /*var list=new List<string>();
                list.Add(words[i]);*/
            }
                Console.ReadLine();
        }
        public static bool Palindrom(string s)
        {
            for (int i = 0; i < s.Length / 2; i++)

                if (s[i] != s[s.Length - i - 1])
                    return false;
            return true;
        }
        private string email;
    }
}
