using System;
using _05.Mediator.Implementation;

namespace _05.Mediator
{
    /// <summary>
    /// Паттрен Mediator предоставляет объект-посредник, скрывающий 
    /// способ взаимодействия нескольких объектов-коллег, что 
    /// обеспечивает слабую связанность системы, избавляя объектов-коллег
    /// от необходимости напрямую взаимодействовать друг с другом,
    /// и явно ссылаться друг на друга
    /// </summary>
    public class Program
    {
        private static void Main()
        {
            var mediator = new SalesMediator();
            var farmer = new Farmer(mediator);
            var shop = new Shop(mediator);

            mediator.Farmer = farmer;
            mediator.Shop = shop;

            farmer.GrowBanana();

            Console.ReadKey();
        }
    }
}
