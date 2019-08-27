using System;

namespace _10.TemplateMethod
{
    class ConcreteClassA : AbstractClass
    {
        protected override void OperationOne()
        {
            Console.WriteLine("Reading lines from file");
        }

        protected override void OperationTwo()
        {
            Console.WriteLine("Parsing lines");
        }

        protected override void OperationThree()
        {
            Console.WriteLine("Printing data to console");
        }
    }
}
