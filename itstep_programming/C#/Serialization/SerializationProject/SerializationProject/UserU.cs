using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Serialization;

namespace SerializationProject
{
    [Serializable]
   public  class UserU
    {
        [XmlAttribute]
       public int age;
         [XmlElement]
        public string fio;
         public UserU() { }
        public UserU(int age, string fio) {
            this.age = age;
            this.fio = fio;
        }
        public override string ToString()
        {
            return fio + " " + age;
        }
    }
}
