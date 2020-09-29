using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShopBooks.DAL.Entities
{
	public class Book
	{
		public int Id { get; set; }
		public string Title { get; set; }
		public decimal Price { get; set; }
		public Nullable<DateTime> Date { get; set; }
	}
}
