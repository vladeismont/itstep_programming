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
using System.Windows.Shapes;

namespace Exampl2Application
{
    /// <summary>
    /// Interaction logic for SecondWindow.xaml
    /// </summary>
    public partial class SecondWindow : Window
    {
        public SecondWindow()
        {
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        { 
           // Обращение из "Дочернего окна"  к свойствам "Главного окна" 
           tblTest.Text=Application.Current.MainWindow.Title;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            // Получение коллекции всех окон приложения 
            WindowCollection windows= App.Current.Windows;
            foreach(Window win in windows)
            {
                // Применение стиля ко  всем окнам!
                win.WindowStyle = WindowStyle.ToolWindow;
            }
        }
    }
}
