namespace _03.Decorator.Abstraction
{
    abstract class Decorator : Component
    {
        public Component Component { protected get; set; }

        public override void Operation()
        {
            Component?.Operation();
        }
    }
}