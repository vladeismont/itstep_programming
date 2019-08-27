namespace _02.Builder
{
    internal class Foreman
    {
        private readonly Builder _builder;

        public Foreman(Builder builder)
        {
            _builder = builder;
        }

        public void Construct()
        {
            _builder.BuildBasement();
            _builder.BuildStorey();
            _builder.BuildRoof();
        }
    }
}