using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*9. Дана строка текста, в которой слова разделены пробелами. Необходимо:
                              - определить количество слов в строке, длина которых меньше заданного числа К;
                              - вычислить, какой процент слов в строке имеет наименьшую длину;
                              - исключить из строки первое и последнее слова, оставшийся текст вывести на экран.
*/
namespace ConsoleApplication105
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "Дана строка текста, в которой слова разделены пробелами";
            int k = 7,s=0;
            string[] separators = { ",", ".", "!", "?", ";", ":", " " };
            string[] words = str.Split(separators, StringSplitOptions.RemoveEmptyEntries);
            foreach (var word in words)
            {
                if (word.Length < k) s++;
            }
            Console.WriteLine("Количество слов, длина которых меньше {0} = {1}",k,s);
            Console.WriteLine("____________________________________________________");
            int Now = 0,i=0;
            str = "..............................";
            foreach (var word in words)
            {
                Now++;
                if (str.Length > word.Length) str = word;
            }
            foreach (var word in words)
            {
                if (str.Length == word.Length) i++;
            }
            Console.WriteLine((double)i/Now*100+"%");
            //Console.WriteLine("самое краткое слово: "+str);
            Console.WriteLine("____________________________________________________");
            string str1 ="Дана строка текста, в которой слова разделены пробелами";
            Console.WriteLine(str1);
            int x = 0;
            x=str1.IndexOf(' ');
            str1=str1.Remove(0, x);
            //Console.WriteLine(str1);
            x = str1.LastIndexOf(' ');
            //Console.WriteLine(x);
            str1 = str1.Remove(x+1);
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.BackgroundColor = ConsoleColor.Magenta;
            Console.WriteLine(str1);
            Console.ForegroundColor = ConsoleColor.White;
            Console.BackgroundColor = ConsoleColor.Black;
            /*char[] arr = str1.ToCharArray();
            Array.Reverse(str1);
             * .StrReverse() use framework 4.5
            Console.WriteLine(str1);*/
        }
    }
}
