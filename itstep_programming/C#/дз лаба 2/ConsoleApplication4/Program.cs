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
            for (int i = 0; i < 256; i++)
                Console.WriteLine("Знак unicode N'{0}' является символ {1}", i, (char)i);
            //1 Ввод строки с клавиатуры. Посчитать сколько слов-палиндромов встречается во всей строке и процент слов-палиндромов в строке (палиндромы – это слова которые читаются слева на право,  точно так же как и справа на лево, напр. «КАЗАК»)  
            string str;
            str = Console.ReadLine();
            if (str == "") { Console.WriteLine("empty");  }
            //Console.WriteLine(str);
            string[] words = str.Split(' ');
            int count = 0;
            for (int i = 0; i < words.Length; i++)
            {
                if (words[0] == "") { count = 0;break; }
                if (Palindrom(words[i])) {
                    ++count;
                }
                /*var list=new List<string>();
                list.Add(words[i]);*/
            }
            double pol;
            if (count == 0)
            {
                pol = 0;
            }
            else
            {
                Console.WriteLine("количество слов: {0}",words.Length);
                Console.WriteLine("количество слов полиндромов: {0}", count);
                pol = (double)count / (double)words.Length;
            }
            Console.WriteLine("% полиндромов: {0:p}", pol);
            Console.WriteLine("lenght: {0}", words.Length);
            Console.WriteLine("rank: {0}", words.Rank);

            //2 Ввод строки с клавиатуры. В словах, имеющих нечетное количество символов, первый символ сделать заглавным
            Console.WriteLine("введите строку");
            str = Console.ReadLine();
            words = str.Split(' ');
            string strtmp;
            var sbtmp = new StringBuilder();
            int n = 0;
            foreach (var word in words)
            {
                ++n;
                if (word.Length % 2 == 1)
                {
                    var sb = new StringBuilder(word);
                    sb[0] = char.ToUpper(sb[0]);
                    strtmp = sb.ToString();
                    if (n == words.Length)
                    {
                        sbtmp.Append(sb);
                    }
                    else
                    {
                        sbtmp.Append(sb + " ");
                    }
                }
                else
                {
                    if (n == words.Length)
                    {
                        sbtmp.Append(word);
                    }
                    else
                    {
                        sbtmp.Append(word + " ");
                    }
                }
            }
            Console.WriteLine(sbtmp);

            //3 Ввод строки с клавиатуры. Отсортировать слова по возрастанию количества последовательных букв.
            Console.WriteLine("введите строку");
            str = Console.ReadLine();
            words = str.Split(' ');
            for (int i = 0; i < words.Length; i++)
            {
                for (int j = 0; j < words.Length - 1; j++)
                {
                    if (needToReOrder(words[j], words[j + 1]))
                    {
                        string s = words[j];
                        words[j] = words[j + 1];
                        words[j + 1] = s;
                    }
                }
            }
            Console.WriteLine("слова после сортировки:");
            var sb1 = new StringBuilder();
            foreach (var word in words)
            {
                sb1.Append(word + ' ');
                Console.WriteLine(word);
            }
            Console.WriteLine(sb1);

            //4 В веденной строке с клавиатуры поменять слова местами (первое с последним, второе с предпоследним и т.д.). Слова имеют разную длину.
            Console.WriteLine("введите строку");
            str = Console.ReadLine();
            words = str.Split(' ');
            string str1 = string.Empty;
            for(int i = 0; i < words.Length; ++i)
            {
                str1 += words[words.Length-i-1]+" ";
            }
            Console.WriteLine(str1);

            //5 	Строка состоит из слов. Слова – это цифры. Сформировать новую строку, где слова будут упорядочены по сумме цифр её образующих.
            Console.WriteLine("#5 введите строку");
            str = Console.ReadLine();
            words = str.Split(' ');
            try
            {
                //int m = Int32.Parse("abc");
                for (int i = 0; i < words.Length; i++)
                {
                    for (int j = 0; j < words.Length - 1; j++)
                    {
                        if (needToReOrder1(words[j], words[j + 1]))
                        {
                            string s = words[j];
                            words[j] = words[j + 1];
                            words[j + 1] = s;
                        }
                    }
                }
                string str2 = string.Empty;
                for (int i = 0; i < words.Length; ++i)
                {
                    str2 += words[i] + " ";
                }
                Console.WriteLine(str2);
            }
            catch (FormatException e)
            {
                Console.WriteLine(e.Message);
            }
            // Output: Input string was not in a correct format.


            Console.ReadLine();
        }
        public static bool Palindrom(string s)
        {
            for (int i = 0; i < s.Length / 2; i++)
                if (s[i] != s[s.Length - i - 1])
                    return false;
            return true;
        }
        protected static bool needToReOrder(string s1, string s2)
        {
            Console.WriteLine("function needToReOrder:");
            for (int i = 0; i < (s1.Length > s2.Length ? s2.Length : s1.Length); i++)
            {
                Console.WriteLine("in function needToReOrder:");
                if (s1.ToCharArray()[i] < s2.ToCharArray()[i]) { Console.WriteLine("< {0}",s1.ToCharArray()[i] < s2.ToCharArray()[i]); return false; }
                if (s1.ToCharArray()[i] > s2.ToCharArray()[i]) { Console.WriteLine("> {0}",s1.ToCharArray()[i] > s2.ToCharArray()[i]); return true; }
            }
            return false;
        }
        protected static bool needToReOrder1(string s1, string s2)
        {
            
            for (int i = 0; i < (s1.Length > s2.Length ? s2.Length : s1.Length); i++)
            {
                int sum1=0, sum2=0;
                for(int j = 0; j < s1.Length; ++j)
                {
                    sum1 += s1.ToCharArray()[j];
                }
                for (int j = 0; j < s2.Length; ++j)
                {
                    sum2 += s2.ToCharArray()[j];
                }
                if (sum1 < sum2) { return false; }
                if (sum1 > sum2) { return true; }
            }
            return false;
        }
    }
}
