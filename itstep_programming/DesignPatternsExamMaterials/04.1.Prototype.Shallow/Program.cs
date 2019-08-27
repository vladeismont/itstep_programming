using System;

namespace _04._1.Prototype.Shallow
{
    /// <summary>
    /// Пример реализации IClineable с использованием метода MemberwiseClone(),
    /// создающего "неполную копию объекта" (Shallow copy) 
    /// </summary>
    internal class Program
    {
        private static void Main()
        {
            var user = new User
            {
                FirstName = "John",
                LastName = "Doe",
                //Credentials = new Credentials
                //{
                //    Login = "johnnydoe",
                //    Password = "qwerty"
                //}
            };

            var clonedUser = user.Clone();

            user.FirstName = "Mark";
            // user.Credentials.Login = "markdoe";

            Console.WriteLine(user);
            Console.WriteLine(clonedUser);

            Console.ReadKey();
        }
    }

    class User : ICloneable
    {
        public string FirstName { get; set; }

        public string LastName { get; set; }

        // public Credentials Credentials { get; set; }

        public object Clone()
        {
            return MemberwiseClone();
        }

        public override string ToString()
        {
            return $"{FirstName} {LastName}";
            // return $"{FirstName} {LastName} [{Credentials.Login}%{Credentials.Password}]";
        }
    }

    class Credentials
    {
        public string Login { get; set; }

        public string Password { get; set; }
    }
}
