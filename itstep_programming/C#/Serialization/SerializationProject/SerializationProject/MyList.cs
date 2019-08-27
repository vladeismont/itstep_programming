using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SerializationProject
{
    [XmlRoot("MyUsers", Namespace="http://tut.by")]
   public  class MyList
    {
       public List<UserU> li = new List<UserU>();
       public MyList() {
           li.Add(new UserU(20, "Ёлкин"));
           li.Add(new UserU(30, "Палкин"));
           li.Add(new UserU(10, "Веткин"));
       }
    }
}
