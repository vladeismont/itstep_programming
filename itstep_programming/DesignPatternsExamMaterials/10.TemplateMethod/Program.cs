using System;

namespace _10.TemplateMethod
{
    /// <summary>
    /// Паттерн Template Method (Шаблонный метод) формирует 
    /// структуру алгоритма и позволяет в производных классах 
    /// реализовать, заместить или переопределить определённые 
    /// шаги алгоритма, не изменяя структуру алгоритма в целом
    /// </summary>
    internal class Program
    {
        private static void Main()
        {
            AbstractClass instance = new ConcreteClassA();
            //instance = new ConcreteClassB();
            instance.TemplateMethod();
            
            Console.ReadKey();
        }
    }
}
