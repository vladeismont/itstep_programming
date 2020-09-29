using GalaSoft.MvvmLight.CommandWpf;
using ShopBooks.BLL.Services;
using ShopBooks.DAL.Entities;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace ShopBooksApp.ViewModel
{
	public class MainWindowViewModel:INotifyPropertyChanged
	{
		ShopBooksService _service;
		public MainWindowViewModel()
		{
			_service = new ShopBooksService();

			_addNewBook = new RelayCommand(AddNewBookExecute);
			_deleteBookCommand = new RelayCommand(AddNewBookExecute);
		}

		private List<Book> _books;
		public List<Book> Books
		{
			get
			{
				if (_books == null)
					_books = _service.GetBooks();
				return _books;
			}
			set {
				_books = value;
				OnPropertyChanged(nameof(Books)); // "Books"
			}
		}

		private Book _addBook;

		public Book AddBook
		{
			get
			{
				if (_addBook == null)
					_addBook = new Book() { Price = 0 };
				return _addBook;
			}
			set {
				_addBook = value;
				OnPropertyChanged(nameof(AddBook)); // "Books"
			}
		}

		private Book _deleteBook;

		public Book DeleteBook
		{
			get { return _deleteBook; }
			set { _deleteBook = value; OnPropertyChanged(nameof(DeleteBook)); }
		}


		private ICommand _addNewBook;
		public ICommand AddNewBook
		{
			get { return _addNewBook; }
		}

		private ICommand _deleteBookCommand;

		public ICommand DeleteBookCommand
		{
			get { return _deleteBookCommand; }
			set { _deleteBookCommand = value; }
		}


		private void AddNewBookExecute()
		{

			_service.AddBook(AddBook);
			AddBook = null;
			Books = null;

		}

		private void DeleteBookExecute()
		{
			_service.DeleteBook(DeleteBook);
			DeleteBook = null;
			Books = null;
		}


		public event PropertyChangedEventHandler PropertyChanged;

		protected virtual void OnPropertyChanged(string propertyName)
		{
			PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
		}

	}
}
