using System;

namespace _01.Adapter
{
    /// <summary>
    /// Адаптер - паттерн предназначенный для обеспечения АДАПТАЦИИ несовместимых интерфейсов
    /// Участники: Клиент, Целевой интерфейс, Адаптируемый интерфейс, Адаптер
    /// Адаптер уровня классов использует наследование от адаптируемого интерфейса,
    /// Адаптер уровня объектов предполагает создание экземпляра адаптируемого класса в теле класса-адаптера
    /// 
    /// Адаптер преобразует интерфейс одного класса в интерфейс другого класса, 
    /// обеспечивая соместную работу классов с несовместимыми интерфейсами, 
    /// которая была бы невозможна без применения адаптера
    /// </summary>
    class Program
    {
        static void Main(string[] args)
        {
            Consumer consumer = new Consumer();
            Provider provider = new ProviderA();
            consumer.Use(provider);
            provider = new ProviderB();
            consumer.Use(provider);

            //consumer.Use(new AdvancedProvider()); // ERROR
            //provider = new ProviderC();
            //consumer.Use(provider);

            Console.ReadKey();
        }
    }
}
