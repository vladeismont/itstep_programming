using System;
using System.Text.RegularExpressions;
using System.Collections.Generic;
/*1.	Необходимо обернуть повторяющиеся слово в <strong> элемент. Например, строка  this is is a test должна быть преобразована в  this is <strong>is</strong> a test.*/
public class Example
{
    public static void Main()
    {
        string input = "This is is is  text with   far  too   much   whitespace.   " +
                       "whitespace. 111";
        Console.WriteLine(input);
        string pattern = "\\S+\\s+";
        pattern = "[ ]+";
        Regex r = new Regex(pattern);
        List<string> words = new List<string>(r.Split(input));
        int x = 0;
        int fl = 0;
        string str = "", res1 = "", f = " ";
        foreach (string word in words)
        {
            fl++;
        }
        foreach (string word in words)
        {
            string replacement = "<strong>" + word + "</strong>";
            if (str == word) { x = 1; };
            string str1 = word;
            str = str1;
            if (x == 1) { res1 += str1.Replace(str1, replacement); x = 0; }
            else { res1 += str1 ;}
            fl--;
            res1 += f;
            if (fl == 1) f = "";
        }
        Console.BackgroundColor = ConsoleColor.Red;
        Console.WriteLine(res1);
        Console.BackgroundColor = ConsoleColor.Black;
        // продублировал ради проверки
        string input1 = "<Mack> I'll I'll be be back back in in a a bit bit.";
        Console.WriteLine(input1);
        pattern = "\\S+\\s+";
        pattern = "[ ]+";
        Regex a = new Regex(pattern);
        List<string> words1 = new List<string>(a.Split(input1));
        x = 0;
        fl = 0;
        str = ""; res1 = ""; f = " ";
        foreach (string word in words1)
        {
            fl++;
        }
        foreach (string word in words1)
        {
            string replacement = "<strong>" + word + "</strong>";
            if (str == word) { x = 1; };
            string str1 = word;
            str = str1;
            if (x == 1) { res1 += str1.Replace(str1, replacement); x = 0; }
            else { res1 += str1; }
            fl--;
            res1 += f;
            if (fl == 1) f = "";
        }
        Console.BackgroundColor = ConsoleColor.Red;
        Console.WriteLine(res1);
        Console.BackgroundColor = ConsoleColor.Black;
    }
}