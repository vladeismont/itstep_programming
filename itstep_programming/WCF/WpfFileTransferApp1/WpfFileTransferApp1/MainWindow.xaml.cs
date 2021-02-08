using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using WpfFileTransferApp1.FileTransferService1;

namespace WpfFileTransferApp1
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        //FileTransferService1.FileTransferService1Client client;
        string path;
        //List<File> list = new List<File>();
        
        public MainWindow()
        {

            InitializeComponent();
            //client = new FileTransferService1.FileTransferService1Client();
        }

        private void pathBtn_Click(object sender, RoutedEventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            fbd.ShowDialog();
            path = fbd.SelectedPath;
            pathLbl.Text = path.ToString();
        }

        private void syncBtn_Click(object sender, RoutedEventArgs e)
        {
            
            if (path != null)
            {
                System.Windows.MessageBox.Show("path!=null");
                File[] myArray = new File[0];

                using (FileTransferService1.FileTransferService1Client client1 = new FileTransferService1.FileTransferService1Client())
                {

                    Array.Resize(ref myArray, myArray.Length + client1.GetFilesInfo().Length);
                    // wait for async callback
                    System.Windows.MessageBox.Show("sleep 1");
                    myArray = client1.GetFilesInfo();
                    // wait for async callback
                    System.Windows.MessageBox.Show("sleep 2");
                    //pathLbl.Text += client.GetFileContent();

                }
                using (FileTransferService1.FileTransferService1Client client1 = new FileTransferService1.FileTransferService1Client())
                {
                    foreach (var i in myArray)
                    {
                        pathLbl.Text += client1.GetFileContent(i).ToString();
                    }
                    

                }
                System.Windows.MessageBox.Show(myArray.Count().ToString());

                foreach (File f in myArray)
                {
                    System.Windows.MessageBox.Show("inside foreach");
                    pathLbl.Text += "!;";
                    pathLbl.Text += f.FilePath.ToString();
                    
                }
                System.Windows.MessageBox.Show("end");
            }

        }
    }
}
