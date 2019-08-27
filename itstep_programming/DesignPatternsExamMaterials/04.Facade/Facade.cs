namespace _04.Facade
{
    internal class Facade
    {
        private readonly SubsystemA _subsystemA;

        private readonly SubsystemB _subsystemB;

        public Facade()
        {
            _subsystemA = new SubsystemA();
            _subsystemB = new SubsystemB();
        }

        public void MakeComplexWork()
        {
            _subsystemA.DoWork();
            _subsystemB.DoSomeWork();
        }
    }
}
