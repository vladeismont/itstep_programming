using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace FileTransferService1
{
    // ПРИМЕЧАНИЕ. Команду "Переименовать" в меню "Рефакторинг" можно использовать для одновременного изменения имени класса "Service1" в коде и файле конфигурации.
    public class FileTransferService1 : IFileTransferService1
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
            //try
            //{
            //Console.WriteLine(Path.Combine(AppDomain.CurrentDomain.BaseDirectory+"/data/"+fileInfo.FilePath));
                var r= System.IO.File.ReadAllBytes(Path.Combine(AppDomain.CurrentDomain.BaseDirectory + "/data/" + fileInfo.FilePath));
                return r;
            //}
            //catch (Exception e)
            //{
            //    Console.WriteLine(e.Message);
            //}
            //throw new NotImplementedException();
        }

        public File[] GetFilesInfo()
        {
            //List<File> list = new List<File>();F:\Step\step\exam\WCF\v1\FileTransferService1\HostConsole1\bin\Debug\data Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "data")
            string[] files =new string[Directory.GetFiles(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "data"), "*.*", SearchOption.AllDirectories).Length];
            Console.WriteLine(Path.Combine("current dir: "+AppDomain.CurrentDomain.BaseDirectory, "data"));
            //arrays = Directory.GetFiles(sdira, "*", SearchOption.AllDirectories).Select(x => Path.GetFileName(x)).ToArray();
            files= Directory.GetFiles(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "data"), "*.*", SearchOption.AllDirectories).Select(x => Path.GetFullPath(x)).ToArray();
            foreach (string f in files)
            {
                Console.WriteLine("P.f: "+f);
            }
            //Directory.GetFiles()
            //foreach (string file in files)
            //{
            //    File fI = new File();
            //    fI.FileDate = System.IO.File.GetLastWriteTime(file);
            //    fI.FileLength = new System.IO.FileInfo(file).Length;

            //    //str.Substring(10, str.Length - 10) skip or str = str.Substring(10);
            //    //AppDomain.CurrentDomain.BaseDirectory + "\\data\\"
            //    //fI.FilePath = file;
            //    fI.FilePath = file.Replace(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "data"), "");
            //    list.Add(fI);
            //}
            //Console.WriteLine("FilesInfo sent;");
            File[] myArray = new File[files.Length];
            //Array.Resize(ref myArray, myArray.Length + files.Length);
            Console.WriteLine("myArray length: " +myArray.Length);

            //int i = 0;
            //foreach(var f1 in files)
            //{
            //    string str = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, Path.Combine("data", f1));
            //    Console.WriteLine(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, Path.Combine("data", f1)));
            //    string st = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "data");
            //    Console.WriteLine("st" + str);
            //    FileInfo fInfo = new FileInfo(str);

            //    myArray[i].FilePath = Path.GetFileName(fInfo.ToString()).ToString();
            //    Console.WriteLine("myArray[i].FilePath" + myArray[i].FilePath);



            //    Console.WriteLine("FileDate: " + System.IO.File.GetCreationTime(str).ToString());
            //    myArray[i].FileDate = System.IO.File.GetCreationTime(str).ToString();
            //    Console.WriteLine("myArray[i].FileDate" + myArray[i].FileDate);

            //    myArray[i].FileLength = new System.IO.FileInfo(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, Path.Combine("data", files[i]))).Length;
            //    Console.WriteLine("myArray[i].FileLength" + myArray[i].FileLength);
            //}

            for (int i = 0; i < myArray.Length; ++i)
            {
                myArray[i] = new File();
                //string str = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, Path.Combine("data", files[i]));
                //Console.WriteLine(files[i]);
                //string st = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "data");
                //Console.WriteLine("st" + str);

                FileInfo fInfo = new FileInfo(files[i]);
                //file.Replace(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "data"), "")
                //string str = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, Path.Combine("data", files[i]));
                myArray[i].FilePath = Path.GetFullPath(fInfo.ToString());
                myArray[i].FilePath = myArray[i].FilePath.Replace(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "data"), "");
                Console.WriteLine("myArray[i].FilePath" + myArray[i].FilePath);



                Console.WriteLine("FileDate: " + System.IO.File.GetLastWriteTime(files[i]).ToString());
                myArray[i].FileDate = System.IO.File.GetCreationTime(files[i]).ToString();
                Console.WriteLine("myArray[i].FileDate" + myArray[i].FileDate);

                myArray[i].FileLength = (new System.IO.FileInfo(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, Path.Combine("data", files[i])))).Length;
                Console.WriteLine("myArray[i].FileLength" + myArray[i].FileLength);

            }
            //foreach (string file in files)
            //{
            //    Array.Resize(ref myArray, myArray.Length + client1.GetFilesInfo().Length);
            //    myArray[myArray.GetUpperBound(0)].FileDate = System.IO.File.GetLastWriteTime(file);
            //    Console.WriteLine(System.IO.File.GetLastWriteTime(file));
            //    myArray[myArray.GetUpperBound(0)].FileLength = new System.IO.FileInfo(file).Length;
            //    Console.WriteLine(new System.IO.FileInfo(file).Length);
            //    myArray[myArray.GetUpperBound(0)].FilePath = file.Replace(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "data"), "");
            //    Console.WriteLine(file.Replace(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "data"), ""));
            //}
            return myArray;
            



            //throw new NotImplementedException();
        }

        //public string GetFileRootDir()
        //{
        //    return AppDomain.CurrentDomain.BaseDirectory;
        //    //throw new NotImplementedException();
        //}
    }
}
