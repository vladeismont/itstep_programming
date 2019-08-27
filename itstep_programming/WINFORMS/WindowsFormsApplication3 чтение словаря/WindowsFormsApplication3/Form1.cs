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
namespace WindowsFormsApplication3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Stream myStream = null;
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            openFileDialog1.InitialDirectory = "c:\\";
            openFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            openFileDialog1.FilterIndex = 2;
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    if ((myStream = openFileDialog1.OpenFile()) != null)
                    {
                        using (myStream)
                        {
                            // Insert code to read the stream here.
                            var reader = new StreamReader(myStream, System.Text.Encoding.GetEncoding(1251));
                            //textBox1.Text = reader.ReadToEnd();
                            while (!reader.EndOfStream)
                            {
                                string source = reader.ReadLine();
                                if (source == "END.") break;
                                //string[] stringSeparators = new string[] { "=" };
                                string[] result = source.Split(new char[] { '=' });
                                textBox1.Text += result[0].ToString()+ "\r\n";
                                textBox2.Text += result[1].ToString() + "\r\n";
                                
                            }
                           
                            reader.Close();
                        }
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not read file from disk. Original error: " + ex.Message);
                }
            }
        }
    }
}
