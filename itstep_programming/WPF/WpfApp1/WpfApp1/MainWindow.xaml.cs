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

namespace WpfApp1
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("clicked");
        }

        private void btnAddNewButton_Click(object sender, RoutedEventArgs e)
        {
            Button newButton = new Button() { Content = "Button in Code" };
            LinearGradientBrush linearBrush = new LinearGradientBrush();
            linearBrush.GradientStops.Add(
                new GradientStop() { Color = Colors.Red, Offset = 0.25 }
                );
            linearBrush.GradientStops.Add(
                new GradientStop() { Color = Colors.Yellow, Offset = 0.5 }
                );
            linearBrush.GradientStops.Add(
                new GradientStop() { Color = Colors.Green, Offset = 0.75 }
                );
            //linearBrush.GradientStops.Add(
            //    new GradientStop() { Color = Colors.Blue, Offset = 1 }
            //    );
            newButton.Background = linearBrush;
            spMain.Children.Add(newButton);

            gradient.GradientStops.Add(new GradientStop() { Color = Colors.Orange, Offset = 1 });
        }
    }
}
