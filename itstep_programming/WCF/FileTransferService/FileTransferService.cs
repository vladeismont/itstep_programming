using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace FileTransferService
{
    // ПРИМЕЧАНИЕ. Команду "Переименовать" в меню "Рефакторинг" можно использовать для одновременного изменения имени класса "Service1" в коде и файле конфигурации.
    [ServiceBehavior(InstanceContextMode = InstanceContextMode.PerCall, ConcurrencyMode = ConcurrencyMode.Multiple)]
    public class FileTransferService : IFileTransferService
    {

        //public string GetData(int value)
        //{
        //    return string.Format("You entered: {0}", value);
        //}

        //public CompositeType GetDataUsingDataContract(CompositeType composite)
        //{
        //    if (composite == null)
        //    {
        //        throw new ArgumentNullException("composite");
        //    }
        //    if (composite.BoolValue)
        //    {
        //        composite.StringValue += "Suffix";
        //    }
        //    return composite;
        //}
        public byte[] GetFileContent(File fileInfo)
        {
            try
            {

                return System.IO.File.ReadAllBytes(AppDomain.CurrentDomain.BaseDirectory + "\\data\\" + fileInfo.FilePath);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            throw new NotImplementedException();
        }

        public List<File> GetFilesInfo()
        {
            List<File> list = new List<File>();
            string[] files = Directory.GetFiles(AppDomain.CurrentDomain.BaseDirectory + "\\data\\", " *.*",SearchOption.AllDirectories);
            foreach (string file in files)
            {
                File fI = new File();
                fI.FileDate = System.IO.File.GetLastWriteTime(file);
                fI.FileLength = new System.IO.FileInfo(file).Length ;

                //str.Substring(10, str.Length - 10) skip or str = str.Substring(10);
                //AppDomain.CurrentDomain.BaseDirectory + "\\data\\"
                //fI.FilePath = file;
                fI.FilePath = file.Replace(AppDomain.CurrentDomain.BaseDirectory + "\\data\\", "");
                list.Add(fI);
            }
            return list;
            //throw new NotImplementedException();
        }

        //public string GetFileRootDir()
        //{
        //    return AppDomain.CurrentDomain.BaseDirectory;
        //    //throw new NotImplementedException();
        //}
    }
}
