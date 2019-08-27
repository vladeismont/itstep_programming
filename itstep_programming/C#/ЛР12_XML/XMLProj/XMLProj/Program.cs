using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml;
using System.Text;
using System.Threading.Tasks;

namespace XMLProj
{
    class Program
    {
        static void Main(string[] args)
        {int count=0;
            XmlTextReader reader;
            try {
                reader = new XmlTextReader("c:\\temp\\students.xml");
                reader.WhitespaceHandling = WhitespaceHandling.None;
                while (reader.Read()) {
                    if (reader.NodeType == XmlNodeType.Element)
                    {
                       /* if (reader.Name == "group") {
                            Console.WriteLine("Номер группы: "+ reader.GetAttribute("id"));
                            Console.WriteLine("Количество атрибутов" + reader.AttributeCount);
                            while (reader.Read() && reader.Name == "user") {

                                if (reader.IsStartElement() && reader.Name == "user") { 
                                Console.WriteLine("Фамилия пользователя: "+reader.GetAttribute("name"));
                                reader.Read();
                                Console.WriteLine("Логин пользователя: " + reader.Value);
                            }
                                


                            }
                        

                        }*/
                    
                    }
                    count++;
                    Console.WriteLine(count);
                    
                  // if(reader.AttributeCount>0)
                  // Console.WriteLine(reader.GetAttribute(0));
                
                
                }


            }
            catch (Exception e) {
                Console.WriteLine(e.Message);
            }

        }
    }
}
