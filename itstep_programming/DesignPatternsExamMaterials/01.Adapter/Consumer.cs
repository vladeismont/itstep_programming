namespace _01.Adapter
{
    class Consumer
    {
        public void Use(Provider p)
        {
            p.Do();
        }
    }
}