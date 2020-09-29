using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Example4XAML
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            button1.Content = "КНОПКА 4";
            
            GradientStopCollection coll = new GradientStopCollection();
            coll.Add(new GradientStop { Color = Colors.YellowGreen, Offset = 0 });
            coll.Add(new GradientStop { Color = Colors.Yellow, Offset = 1 });
            button1.Background = new LinearGradientBrush(coll);
        }
    }
}
