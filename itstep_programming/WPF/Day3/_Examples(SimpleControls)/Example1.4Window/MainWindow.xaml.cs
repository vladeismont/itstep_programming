using System.Windows;
using System.Windows.Input;

namespace Example1._4Window
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

        private void buttonClose_Click(object sender, RoutedEventArgs e)
        {
            // закрываем приложение
            //Application.Current.Shutdown();  
          
            // закрываем окно
            this.Close();
        }

        private void Window_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            this.DragMove();  // метод перетягивания окна
        }
    }
}
