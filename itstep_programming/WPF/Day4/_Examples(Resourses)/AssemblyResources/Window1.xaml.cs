using System;
using System.Collections;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Windows;
using System.Windows.Media.Imaging;
using System.Windows.Resources;

namespace AssemblyResources
{
    public partial class Window1 : System.Windows.Window
    {
        public Window1()
        {
            InitializeComponent();
        }

        private void cmdPlay_Click(object sender, RoutedEventArgs e)
        {
            // ������������� ������� BitmapImage, ������� ������������ ������ � ��������� ����� Uri
            img.Source = new BitmapImage(new Uri("images/winter.jpg", UriKind.Relative)); // ������������� ���� 
 
            //img.Source = new BitmapImage(new Uri("pack://application:,,,/images/winter.jpg", UriKind.Absolute)); // ���������� ����
        }

        // ������ ��������.
        private void buttonGetResource_Click(object sender, RoutedEventArgs e)
        {
            // ��������� ������� �������.
            StreamResourceInfo resInfo = Application.GetResourceStream(new Uri("test.txt", UriKind.Relative));
            MessageBox.Show("��� �������: " + resInfo.ContentType);

            // ������ ������.
            using (StreamReader reader = new StreamReader(resInfo.Stream, System.Text.Encoding.Default))
            {
                string textFromRes = reader.ReadToEnd();
                MessageBox.Show(textFromRes);
            }
        }

        // ��������� ���� ��������.
        private void buttonGetAllResources_Click(object sender, RoutedEventArgs e)
        {
            Assembly assembly = Assembly.GetAssembly(this.GetType());
            
            string resourceName = assembly.GetName().Name + ".g";

            // ��������� �������� ������ � ������� (�� ������ ��������) �� ����� ����������.
            ResourceManager rm = new ResourceManager(resourceName, assembly);
            using (ResourceSet set = rm.GetResourceSet(CultureInfo.CurrentCulture, true, true))
            {
                string result = string.Empty;
                foreach (DictionaryEntry item in set)
                {
                    result += item.Key.ToString() + Environment.NewLine;
                }
                MessageBox.Show(result);
            }
        }
    }
}