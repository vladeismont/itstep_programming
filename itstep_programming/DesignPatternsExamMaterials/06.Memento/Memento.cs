namespace _06.MementoSample
{
    /// <summary>
    /// Хранитель
    /// </summary>
    internal class Memento
    {
        public string State { get; set; }

        public Memento(string state)
        {
            State = state;
        }
    }
}