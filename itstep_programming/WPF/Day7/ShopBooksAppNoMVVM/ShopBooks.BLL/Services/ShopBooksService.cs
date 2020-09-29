using ShopBooks.DAL.Context;
using ShopBooks.DAL.Entities;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShopBooks.BLL.Services
{
	public class ShopBooksService
	{
		public DbContext db;
		public ShopBooksService()
		{
			db = new ShopBooksContext();
		}
		public int GetCountBooks()
		{
			return (db as ShopBooksContext).Books.Count();
		}

		public List<Book> GetBooks()
		{
			return (db as ShopBooksContext).Books.ToList();
		}

		public void DeleteBook(Book book)
		{
			(db as ShopBooksContext).Books.Remove(book);
			db.SaveChanges();
		}

		public void AddBook(Book book)
		{
			(db as ShopBooksContext).Books.Add(book);
			db.SaveChanges();
		}

		public void Save()
		{
			db.SaveChanges();
		}

	}
}
