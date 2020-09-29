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

namespace Example3Properties
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            tbText2.Text = "Текст 2";                                   // текст 
            tbText2.Foreground = new SolidColorBrush(Colors.Red);       // цвет шрифта
            tbText2.Background = new SolidColorBrush(Colors.Beige);     // цвет фона
            tbText2.BorderBrush = new SolidColorBrush(Colors.Aqua);     // цвет границы
            tbText2.BorderThickness = new Thickness(1, 2, 3, 4);        // толщина границы
            tbText2.Padding = new Thickness(4,8,4,8);                   // внутренни отступы 
            tbText2.HorizontalAlignment = HorizontalAlignment.Center;   // выравнивание по горизонтали 
            tbText2.VerticalAlignment = VerticalAlignment.Top;          // выравнивание по вертикали 

            tbText2.FontFamily = new FontFamily("Arial");               //  тип шрифта
            tbText2.FontSize = 12;                                      //  размер шрифта
            tbText2.FontStretch = FontStretches.ExtraCondensed;         //  степень сжатия/расширения шрифта
            tbText2.FontWeight = FontWeights.Bold;                      //  толщина шрифта
            
            tbText2.IsTabStop=false;                                    // включен ли элемент при переходе по Tab
            tbText2.TabIndex=2;                                         // № п/п элемента при переходе по Tab

            tbText2.Height=50;                                          // высота
            tbText2.Width=150;                                          // ширина
            tbText2.MaxHeight=50;                                       // максимальная высота 
            tbText2.MinHeight = 30;                                     // минимальная высота 
            tbText2.MaxWidth = 150;                                     // максимальная ширина 
            tbText2.MinWidth = 50;                                      // минимальная ширина 

            tbText2.Visibility=Visibility.Visible;                      // видимость элемента (видимый)
            //tbText2.Visibility = Visibility.Collapsed;                  // видимость элемента (не видимый элемент и не занимает место в компоновке)
            //tbText2.Visibility = Visibility.Hidden;                     // видимость элемента (не видимый элемент и занимает место в компоновке)

            tbText2.Focusable=true;                                     // поддержка фокуса
            tbText2.IsEnabled = true;                                   // доступоность элемента

            

        }
    }
}
