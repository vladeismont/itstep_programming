using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
        private int _pictureIndex = 0;
        private void button1_Click(object sender, EventArgs e)
        {
            string filePath = "D:/eismontvlad/winforms/pictures";
            string[] files = Directory.GetFiles(filePath);
            _pictureIndex++;
            if (_pictureIndex >= files.Length)
            {
                _pictureIndex = 0;
            }
            pictureBox1.Image = Image.FromFile(files[_pictureIndex]);
        }
    }
}
