using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;

namespace DemoBinding.Converters
{
    public class FontSizeConverter:IValueConverter
    {

        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            double fontSize = (double)value;
            if (fontSize < 15) return "small";
            if (fontSize >= 15 && fontSize < 50) return "middle";
            return "big";
        }

        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            string fontSize = value.ToString();
            if (fontSize.Equals("small")) return 15;
            if (fontSize.Equals("middle")) return 50;
             return 70;
        }
    }
}
