using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Example5ExtendMarkup
{
    public static class TextInfo
    {
        public static string Test { get; set; }

        static TextInfo()
        {
            Test = "Тестовая строка";
        }
    }
}
