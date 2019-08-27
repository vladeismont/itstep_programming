namespace _01.ChainOfResponsibility.Abstraction
{
    /// <summary>
    /// Обработчик запроса (предоставляет интерфейс для обработки запросов)
    /// </summary>
    abstract class Handler
    {
        public Handler Successor { get; set; }

        public abstract void HandleRequest(int request);
    }
}