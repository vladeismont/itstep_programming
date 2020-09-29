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

namespace Example9Dinamic
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
   

     private void CheckBox_Checked(object sender, RoutedEventArgs e)
        {
            Btn_next.Content = "--> Next other page and window";
            Btn_prev.Content = "<-- Prev other page and window";
        }

        private void CheckBox_Unchecked(object sender, RoutedEventArgs e)
        {
            Btn_next.Content = "> Next";
            Btn_prev.Content = "< Prev";
        }
    }
}
