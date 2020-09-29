using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;

namespace firstweb.models
{
    public class User
    {
        public int Id { get; set; }
        public string Login { get; set; }
        public string Password { get; set; }
    }
    public class UserDBContext : DbContext
    {
        public DbSet<User> Users { get; set; }


        public UserDBContext() : base("DefaultConnection")
        {
            
        }

        
    }

    //public class UserDbInitializer : DropCreateDatabaseAlways<UserDBContext>
    //{
    //    protected override void Seed(UserDBContext context)
    //    {
    //        //base.Seed(context);

    //        context.Users.AddRange(new List<User> {
    //            {new User { Id = 1, Login = "Vasya", Password = "Pupkin"} },
    //            {new User{ Id = 2, Login = "Petya", Password = "Ivanov"} }
    //        });
    //        context.SaveChanges();
    //    }
    //}
}