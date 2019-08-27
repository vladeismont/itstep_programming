namespace _02.Composite.Abstraction
{
    abstract class Component
    {
        public string Name { get; }

        protected Component(string name)
        {
            Name = name;
        }

        public abstract void Operation();

        public abstract void Add(Component item);

        public abstract void Remove(Component item);

        public abstract Component GetChild(int index);
    }
}
