using System;

namespace _10.TemplateMethod
{
    class ConcreteClassB : AbstractClass
    {
        protected override void OperationOne()
        {
            Console.WriteLine("Reading lines from database");
        }

        protected override void OperationTwo()
        {
            Console.WriteLine("Parsing lines");
        }

        protected override void OperationThree()
        {
            Console.WriteLine("Sending data by e-mail");
        }
    }
}