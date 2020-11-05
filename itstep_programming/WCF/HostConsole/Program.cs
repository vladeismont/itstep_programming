using System;
using System.ServiceModel;

namespace HostConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            using (ServiceHost host = new ServiceHost(typeof(FileTransferService.FileTransferService)))
            {
                host.Open();
                
                Console.WriteLine("host started @"+DateTime.Now.ToString());

                Console.ReadKey();
            }
        }
    }
}
