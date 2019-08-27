namespace _05.Singleton
{
    internal class Singleton
    {
        public static Singleton Instance { get; } = new Singleton();

        private Singleton()
        {
            State = "Initial state";
        }

        public string State { get; set; }
    }
}