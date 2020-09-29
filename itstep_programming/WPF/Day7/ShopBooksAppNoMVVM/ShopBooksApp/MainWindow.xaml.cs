using ShopBooks.BLL.Services;
using ShopBooks.DAL.Entities;
using System.Windows;
using System.Linq;
namespace ShopBooksApp
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		private ShopBooksService service;
		Book newBook = new Book() { Price = 0 };
		
		public MainWindow()
		{
			InitializeComponent();
			service = new ShopBooksService();
			Layout.DataContext = newBook;
		}

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			dgMain.ItemsSource = service.GetBooks();
		}

		private void btnDelete_Click(object sender, RoutedEventArgs e)
		{
			var selectBook = dgMain.SelectedItem as Book;
			if (selectBook != null)
			{
				service.DeleteBook(selectBook);
				dgMain.ItemsSource = service.GetBooks();
			}
		}

		private void btnAddBook_Click(object sender, RoutedEventArgs e)
		{
			service.AddBook(newBook);
			dgMain.ItemsSource = service.GetBooks();

			newBook = new Book() { Price=0};
			Layout.DataContext = newBook;
		}

		private void btnSaveBook_Click(object sender, RoutedEventArgs e)
		{
			service.Save();
			dgMain.ItemsSource = service.GetBooks();
		}
		
	}
}
