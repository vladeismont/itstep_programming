using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[10];
            int x, sum = 0;

            try
            {
                for (int i = 0; i < 10; ++i)
                {
                    Console.WriteLine("введите число #{0}", i+1);
                    x = int.Parse(Console.ReadLine());
                    arr[x] = x;
                    sum += x;
                    if (sum > 10)
                    {
                        //UserNotFoundException exc = new UserNotFoundException("сумма больше 10");
                        throw new UserNotFoundException("сумма больше 10");
                    }
                }
            }
            catch (IndexOutOfRangeException e)
            {
                Console.WriteLine(e.Message);
            }
            catch(UserNotFoundException exc)
            {
                Console.WriteLine(exc.Message);
            }
            Console.ReadKey();
        }
        public class UserNotFoundException : ApplicationException
        {
            public UserNotFoundException() { }

            public UserNotFoundException(string message) : base(message) { }
        }
    }
}
