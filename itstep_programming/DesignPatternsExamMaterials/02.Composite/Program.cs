using System;
using _02.Composite.Implementation;

namespace _02.Composite
{
    // Предназначение паттерна компоновщик - построение деревьев.
    // Паттерн компоновщик позволяет избавить клиента от необходимости знать,
    // работает ли он с листовым или составным(композитным) элементом дерева
    class Program
    {
        static void Main(string[] args)
        {
            var tree = new Implementation.Composite("Tree");
            var firstBranch = new Implementation.Composite("First branch");
            var secondBranch = new Implementation.Composite("Second branch");
            var leaf1 = new Leaf("leaf one");
            var leaf2 = new Leaf("leaf two");

            tree.Add(firstBranch);
            tree.Add(secondBranch);
            firstBranch.Add(leaf1);
            secondBranch.Add(leaf2);

            // рекурсивный обход дерева
            tree.Operation();
            
            Console.ReadKey();
        }
    }
}
