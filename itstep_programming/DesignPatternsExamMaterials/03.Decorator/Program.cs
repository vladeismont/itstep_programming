using System;
using _03.Decorator.Abstraction;
using _03.Decorator.Implementation;

namespace _03.Decorator
{
    // Паттерн декоратор позволяет динамически подключать 
    // дополнительное состояние и поведение к существующим классам
    // без изменения код исходного класса
    class Program
    {
        static void Main(string[] args)
        {
            Component component = new ConcreteComponent();
            Abstraction.Decorator decoratorA = new ConcreteDecoratorA();
            Abstraction.Decorator decoratorB = new ConcreteDecoratorB();

            decoratorA.Component = component;
            decoratorB.Component = decoratorA;

            decoratorB.Operation();

            Console.ReadKey();
        }
    }
}
