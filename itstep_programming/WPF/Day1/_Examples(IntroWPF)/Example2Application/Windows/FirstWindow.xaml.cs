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

namespace Exampl2Application
{
   
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {  
            // Использование свойства через Application.Current.Properties
            btnFirst.Content = Application.Current.Properties["GlobalValue"];
        }

        // Создание элемента управления в коде
        private void btnSecond_Click(object sender, RoutedEventArgs e)
        {
            // Создание объекта класса Button
            Button btnInCode = new Button();
            btnInCode.Height = 60;
            btnInCode.Width = 150;
            btnInCode.Content = "Кнопка из кода";
            // Реализация события Click
            btnInCode.Click += (obj, ea) =>
                {
                    Color color = Color.FromRgb(255, 0, 0);
                    SolidColorBrush brush = new SolidColorBrush(color);
                    btnSecond.Background = brush;
                };
            // Добавление созданного элемента в колелкцию дочерних элементов
            // grdMain - элемент компоновки Grid
            grdMain.Children.Add(btnInCode);
        }

        // Создание и открытие окна SecondWindow
        private void btnNewWin_Click(object sender, RoutedEventArgs e)
        {
            SecondWindow secWin = new SecondWindow();
            secWin.Show();        // открытие окна в немодальном режиме
            secWin.ShowDialog();  // открытие окна в модальном режиме
        }

       
    }
}
