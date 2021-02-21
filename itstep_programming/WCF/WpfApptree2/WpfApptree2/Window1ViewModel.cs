using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace WpfApptree2
{
    class Window1ViewModel : INotifyPropertyChanged
    {
        public Window1ViewModel()
        {
            _folders = new ObservableCollection<Folder>(Sample.GetFoldersAndFiles());
        }

        private ObservableCollection<Folder> _folders;

        public ObservableCollection<Folder> Folders
        {
            get { return _folders; }
            set { _folders = value; OnPropertyChanged(); }
        }

        public event PropertyChangedEventHandler PropertyChanged;

        protected void OnPropertyChanged([CallerMemberName] string propertyName = "")
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }

    }
}
