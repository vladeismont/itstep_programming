using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void DigitButton_Click(object sender, EventArgs e)
        {
            var control = (Control)sender;//получили объект, пославший событие - нажатую кнопку
            var tag = (String)control.Tag;//взяли первую букву и передали в метод
            AddDigit(tag[0]);
            //AddDigit( ((Control)sender).Tag.ToString()[0] );
        }
        private void Digit1_Click(object sender, EventArgs e)
        {
            //AddDigit('1');
            AddDigit(((Control)sender).Tag.ToString()[0]);
        }
        private void AddDigit(char digit)
        {
            if (Display.Text.Length < 8)
            {
                Display.Text += digit;
            }
        }

    }
}
