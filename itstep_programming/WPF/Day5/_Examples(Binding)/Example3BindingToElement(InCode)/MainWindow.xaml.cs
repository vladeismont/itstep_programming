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

namespace Example3BindingToElement_InCode_
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            Binding binding = new Binding();             // создание объекта привязки данных 
            binding.Source = sliderFontSize;             // указываем источник привязки (объект с которым связываемся) 
            binding.Path = new PropertyPath("Value");    // указываем свойство, к которому привязываемся
            binding.Mode = BindingMode.TwoWay;           // указываем тип привязки

            // Первый способ настройки привязки данных
            // Используется для реализации привязки к элементам управления, 
            // наследующим  FrameworkElement или FrameworkContentElement

            tbText.SetBinding(TextBlock.FontSizeProperty, binding); 
            
            // Второй способ настройки привязки данных
            // BindingOperations.SetBinding(tbText, TextBlock.FontSizeProperty, binding);
            // Достоинство статического меотда: открывается возможность осуществлять привязку к объектам, 
            // не наследующим ни FrameworkElement, ни FrameworkContentElement

        }

        public void ClickButton(object sender, RoutedEventArgs e)
        {
            Button button = (Button)sender;
            tbText.FontSize = Convert.ToDouble(button.Tag);
        }

        private void btnDelAllBindings_Click(object sender, RoutedEventArgs e)
        {
            BindingOperations.ClearBinding(tbText, TextBlock.FontSizeProperty);
        }

        private void btnDelBinding_Click(object sender, RoutedEventArgs e)
        {
            BindingOperations.ClearAllBindings(tbText);
        }
    }
}
