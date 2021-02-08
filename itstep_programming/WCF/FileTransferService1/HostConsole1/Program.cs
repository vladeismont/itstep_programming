using FileTransferService1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace HostConsole1
{
    class Program
    {
        static void Main(string[] args)
        {
            using (ServiceHost host = new ServiceHost(typeof(FileTransferService1.FileTransferService1)))
            {
                host.Open();

                Console.WriteLine("host started @" + DateTime.Now.ToString());

                Console.ReadKey();
            }
        }
    }
}
