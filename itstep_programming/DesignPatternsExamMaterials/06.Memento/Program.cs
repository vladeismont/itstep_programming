using System;

namespace _06.MementoSample
{
    /// <summary>
    /// Паттерн Memento (Хранитель), не нарушая инкапсуляции,
    /// фиксирует и выносит за пределы объекта-хозяина его внутреннее состояние 
    /// так, чтобы его позднее можно было восстановить в исходном моменте-хозяине
    /// </summary>
    internal class Program
    {
        private static void Main()
        {
            Originator originator = new Originator();
            originator.State = "On";

            Caretaker caretaker = new Caretaker();
            caretaker.Memento = originator.CreateMemento();

            originator.State = "Off";

            originator.SetMemento(caretaker.Memento);

            Console.WriteLine(originator.State);

            Console.ReadKey();
        }
    }
}
