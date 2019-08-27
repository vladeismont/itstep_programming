namespace _10.TemplateMethod
{
    abstract class AbstractClass
    {
        protected abstract void OperationOne();

        protected abstract void OperationTwo();

        protected abstract void OperationThree();

        public void TemplateMethod()
        {
            OperationOne();
            OperationTwo();
            OperationThree();
        }
    }
}
