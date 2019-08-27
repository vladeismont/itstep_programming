using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SerializationProject
{
    class Program
    {
        static void Main(string[] args)
        {
           /* UserU u1 = new UserU(22, "Ёлкин");
            UserU u2 = new UserU(25, "Палкин");
            BinaryFormatter bi = new BinaryFormatter();
            Stream fstream = new FileStream("c:\\temp\\out.dat",FileMode.OpenOrCreate, FileAccess.Write,FileShare.None);
            bi.Serialize(fstream, u1);
            bi.Serialize(fstream, u2);
            fstream.Close();*/
            /*UserU v;
            BinaryFormatter bi = new BinaryFormatter();
            Stream fstream = new FileStream("c:\\temp\\out.dat", FileMode.Open, FileAccess.Read, FileShare.None);
             v=(UserU)bi.Deserialize(fstream);
             Console.WriteLine(v.ToString());*/
          /* UserU u1 = new UserU(22, "Ёлкин");
           UserU u2 = new UserU(25, "Палкин");
            XmlSerializer xmls = new XmlSerializer(typeof(UserU));
            Stream fstream = new FileStream("c:\\temp\\out.xml", FileMode.OpenOrCreate, FileAccess.Write, FileShare.None);
            xmls.Serialize(fstream, u1);
            xmls.Serialize(fstream, u2);
            fstream.Close();*/
            XmlSerializerNamespaces ns = new XmlSerializerNamespaces();
            ns.Add("myTUT", "http://tut.by");
            XmlSerializer xmls = new XmlSerializer(typeof(MyList));
            Stream fstream = new FileStream("c:\\temp\\out.xml", FileMode.OpenOrCreate, FileAccess.Write, FileShare.None);
            MyList li = new MyList();
            xmls.Serialize(fstream, li,ns);
            fstream.Close();

        }
    }
}
