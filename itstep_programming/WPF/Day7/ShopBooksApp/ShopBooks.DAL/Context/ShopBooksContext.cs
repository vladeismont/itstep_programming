using ShopBooks.DAL.Entities;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShopBooks.DAL.Context
{
	public class ShopBooksContext:DbContext
	{
		public ShopBooksContext()
			:base("csBooksDb")
		{

		}

		public DbSet<Book> Books { get; set; }

	}
}
