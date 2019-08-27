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
        public string SurName { get; set; }

        public ICollection<Message> Messages { get; set; }
    }

    public class Message {
        [Key]
        public int Id { get; set; }
        [Required]
        [StringLength(20)]
        public string Text { get; set; }
       
        public int UserId { get; set; }

        public User User { get; set; }
        
    }

    class MyContextInitializer : DropCreateDatabaseIfModelChanges<UserContext> {
        protected override void Seed(UserContext db) {
            User user1 = new User { Name = "Tom", Age = 33 };
            User user2 = new User { Name = "Sam", Age = 26 };

            //// добавляем их в бд
            db.Users.Add(user1);
            db.Users.Add(user2);

            db.SaveChanges();

            Message msg1 = new Message { Text = "t1", UserId = 1 };
            Message msg2 = new Message { Text = "t2", UserId = 1 };
            Message msg3 = new Message { Text = "t3", UserId = 1 };
            Message msg4 = new Message { Text = "t4", UserId = 2 };

            // добавляем их в бд
            db.Messages.Add(msg1);
            db.Messages.Add(msg2);
            db.Messages.Add(msg3);
            db.Messages.Add(msg4);

            db.SaveChanges();
        }
    }

    class UserContext : DbContext {
        public UserContext()
            : base("DBConnection") { }

        static UserContext()
        {
            Database.SetInitializer<UserContext>(new MyContextInitializer());
        }

        public DbSet<User> Users { get; set; }
        public DbSet<Message> Messages { get; set; }
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

                ////// добавляем их в бд
                //db.Users.Add(user1);
                //db.Users.Add(user2);

                //db.SaveChanges();
                //Console.WriteLine("Объекты успешно сохранены");
                //Message msg1 = new Message { Text = "t1", UserId = 1 };
                //Message msg2 = new Message { Text = "t2", UserId = 1 };
                //Message msg3 = new Message { Text = "t3", UserId = 1 };
                //Message msg4 = new Message { Text = "t4", UserId = 2 };

                //// добавляем их в бд
                //db.Messages.Add(msg1);
                //db.Messages.Add(msg2);
                //db.Messages.Add(msg3);
                //db.Messages.Add(msg4);

                //db.SaveChanges();
                //Console.WriteLine("Объекты успешно сохранены");

                //// получаем объекты из бд и выводим на консоль
                //var users = db.Users;
                //Console.WriteLine("Список объектов:");
                //foreach (User u in users) {
                //    Console.WriteLine("{0}.{1} - {2}", u.Id, u.Name, u.Age);
                //}

                //var users = db.Users.ToList();
                //foreach (User u in users) {
                //    foreach (Message msg in u.Messages) {
                //        Console.WriteLine("{0}: {1}", u.Name, msg.Text);
                //    }
                    
                //}

                var messages = db.Messages.Include(p => p.User).ToList();
                foreach (Message msg in messages) {
                    Console.WriteLine("{0}: {1}", msg.Text, msg.User.SurName);
                }
            }
        }
    }
}
