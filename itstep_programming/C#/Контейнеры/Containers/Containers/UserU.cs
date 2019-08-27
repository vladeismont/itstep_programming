using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Containers
{
    class UserU//: IComparable
    {
        public int id;
        public string fio;
        public UserU(int id, string fio) {
            this.id = id;
            this.fio = fio;
        }
        public override string ToString() {

            return id + " " + fio;
        }

    /*    public int CompareTo(object obj)
        {
            UserU x = this;
            UserU y = (UserU)obj;
            if (x.id > y.id)
                return 1;
            else if (x.id == y.id)
                return 0;
            else return -1;

        }*/
    }
}
