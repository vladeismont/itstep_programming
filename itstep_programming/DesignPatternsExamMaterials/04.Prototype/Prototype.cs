namespace _04.Prototype
{
    internal abstract class Prototype
    {
        public int Id { get; set; }

        protected Prototype(int id)
        {
            Id = id;
        }

        public abstract Prototype Clone();
    }
}