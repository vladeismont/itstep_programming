using DemoControls.Windows;
using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.IO;
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

namespace DemoControls
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

		private void btnOpen_Click(object sender, RoutedEventArgs e)
		{
			OpenFileDialog openFileDialog = new OpenFileDialog();
			if (openFileDialog.ShowDialog().Value)
			{
				var contentFile = File.ReadAllText(openFileDialog.FileName, Encoding.Default);
				tbMain.Text = contentFile;
			}
		}

		private void btnSave_Click(object sender, RoutedEventArgs e)
		{

		}

		private void btnClose_Click(object sender, RoutedEventArgs e)
		{
			this.Close();
		}

		private void btnAbout_Click(object sender, RoutedEventArgs e)
		{
			AboutWindow aboutWin = new AboutWindow();
			aboutWin.Owner = this;
			aboutWin.ShowDialog();

		}
	}
}
