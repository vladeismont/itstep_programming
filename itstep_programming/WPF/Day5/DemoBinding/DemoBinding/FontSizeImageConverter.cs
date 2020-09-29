using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;

namespace DemoBinding.Converters
{
      public class FontSizeImageConverter:IValueConverter
    {

        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            double fontSize = (double)value;
            if (fontSize < 15) return "/Images/font_delete.png";
            if (fontSize >= 15 && fontSize < 50) return "/Images/font.png";
            return "/Images/font_add.png";
        }

        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
