using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Entity;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.ComponentModel.DataAnnotations;

namespace WindowsFormsApplication7 {

    

    public class User {
        [Key]
        public int Id { get; set; }
        [Required]
        [StringLength(20)]
        public string Name { get; set; }
        public int Age { get; set; }
    }

    class UserContext : DbContext {
        public UserContext()
            : base("DBConnection") { }

        public DbSet<User> Users { get; set; }
    }
    public partial class Form1 : Form {
        public Form1() {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e) {
            using (UserContext db = new UserContext()) {
                //// создаем два объекта User
                //User user1 = new User { Name = "Tom", Age = 33 };
                //User user2 = new User { Name = "Sam", Age = 26 };

                //// добавляем их в бд
                //db.Users.Add(user1);
                //db.Users.Add(user2);

                //db.SaveChanges();
                //Console.WriteLine("Объекты успешно сохранены");

                //// получаем объекты из бд и выводим на консоль
                //var users = db.Users;
                //Console.WriteLine("Список объектов:");
                //foreach (User u in users) {
                //    Console.WriteLine("{0}.{1} - {2}", u.Id, u.Name, u.Age);
                //}

                var users = db.Users
                    .Where(b => b.Age > 20)
                    .OrderByDescending(b=> b.Age);
                foreach (User u in users) {
                    Console.WriteLine("{0}.{1} - {2}", u.Id, u.Name, u.Age);
                }
                GetHashCode first
            }
        }
    }
}
