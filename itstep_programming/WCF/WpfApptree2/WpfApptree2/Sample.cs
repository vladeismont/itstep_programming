using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;

namespace WpfApptree2
{
    class Sample
    {
        public static List<Folder> GetFoldersAndFiles()
        {

            var folders = new List<Folder>();

            Folder folder1 = new Folder { Name = "Folder 1" };
            Folder folder2 = new Folder { Name = "Folder 2" };
            Folder folder3 = new Folder { Name = "Folder 3" };
            Folder folder11 = new Folder { Name = "Folder 11" };
            Folder folder12 = new Folder { Name = "Folder 12" };
            Folder folder22 = new Folder { Name = "Folder 22" };

            folder1.Folders.Add(folder11);
            folder1.Folders.Add(folder12);
            folder2.Folders.Add(folder22);
            Folder folder111 = new Folder { Name = "Folder 111" };
            folder11.Folders.Add(folder111);

            File file1 = new File { Name = "File 1" };

            File file2 = new File { Name = "File 2" };
            File file3 = new File { Name = "File 3" };
            File file4 = new File { Name = "File 4" };

            //file1.Files.Add(file3);
            //file1.Files.Add(file4);

            folder11.Files.Add(file1);
            folder11.Files.Add(file2);
            folder2.Files.Add(file3);
            folder3.Files.Add(file4);

            folders.Add(folder1);
            folders.Add(folder2);
            folders.Add(folder3);
            

            return folders;

        }
    }


    public class Folder
    {
        public Folder()
        {
            Folders = new List<Folder>();
            Files = new List<File>();
        }

        public string Name { get; set; }
        public ICollection<Folder> Folders { get; set; }
        public ICollection<File> Files { get; set; }
        public IList Children
        {
            get
            {
                return new CompositeCollection()
        {
            new CollectionContainer() { Collection = Folders },
            new CollectionContainer() { Collection = Files }
        };
            }
        }
        //public List<Folder> MyProperty { get { return Folders }; set { Folders=new Folders() }; }
    }

    public class File
    {
        public File()
        {
            //Files = new List<File>();
        }

        public string Name { get; set; }
        //public Folder Folder { get; set; }
        //public ICollection<File> Files { get; set; } // This groups files together under a single file.
    }
}
