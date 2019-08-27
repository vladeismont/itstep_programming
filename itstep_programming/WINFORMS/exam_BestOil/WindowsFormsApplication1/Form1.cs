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
        double oil76 = 6.40;
        double oil92 = 7.40;
        double oil95 = 8.40;
        double res, sum = 0;
        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            textBox1.Enabled = true; // Включён
            textBox2.Enabled = false; // Отключён
            textBox1.Text = "";
            textBox2.Text = "";

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            if (textBox2.Text != "")
            {
                if (!double.TryParse(textBox2.Text, out res))
                    MessageBox.Show("The value cannot be parsed");
                label9.Text = res.ToString();
                //label16.Text = res.ToString();
            }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            textBox2.Enabled = true; // Включён
            textBox1.Enabled = false; // Отключён
            textBox1.Text = "";
            textBox2.Text = "";
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox1.SelectedItem.ToString() == "А-76") textBox3.Text = oil76.ToString();
            if (comboBox1.SelectedItem.ToString() == "АИ-92") textBox3.Text = oil92.ToString();
            if (comboBox1.SelectedItem.ToString() == "АИ-95") textBox3.Text = oil95.ToString();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text != "")
            {
                if (!double.TryParse(textBox1.Text, out res))
                    MessageBox.Show("The value cannot be parsed");
                if(textBox3.Text!="")
                label9.Text = string.Format("{0:0.00}", ((double.Parse(textBox3.Text))*res));
                //label16.Text = string.Format("{0:0.00}", ((double.Parse(textBox3.Text)) * res));
            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                textBox4.ReadOnly = false;
                textBox4.Enabled = true;
            }
            if (!checkBox1.Checked)
            {
                textBox4.ReadOnly = true;
                textBox4.Enabled = false;
                textBox4.Text = "0";
            }
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked)
            {
                textBox5.ReadOnly = false;
                textBox5.Enabled = true;
            }
            if (!checkBox2.Checked)
            {
                textBox5.ReadOnly = true;
                textBox5.Enabled = false;
                textBox5.Text = "0";
            }
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            label11.Text = (int.Parse(textBox4.Text) * double.Parse(textBox8.Text) + int.Parse(textBox5.Text) * double.Parse(textBox9.Text) + int.Parse(textBox6.Text) * double.Parse(textBox10.Text) + int.Parse(textBox7.Text) * double.Parse(textBox11.Text)).ToString();
        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {
            label11.Text = (int.Parse(textBox4.Text) * double.Parse(textBox8.Text) + int.Parse(textBox5.Text) * double.Parse(textBox9.Text) + int.Parse(textBox6.Text) * double.Parse(textBox10.Text) + int.Parse(textBox7.Text) * double.Parse(textBox11.Text)).ToString();
        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {
            label11.Text = (int.Parse(textBox4.Text) * double.Parse(textBox8.Text) + int.Parse(textBox5.Text) * double.Parse(textBox9.Text) + int.Parse(textBox6.Text) * double.Parse(textBox10.Text) + int.Parse(textBox7.Text) * double.Parse(textBox11.Text)).ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //textBox4.Text = "5";
            label16.Text = (double.Parse(label9.Text) + double.Parse(label11.Text)).ToString();
            sum += double.Parse(label16.Text);
            label18.Text = sum.ToString();
            label9.Text = "0";
            textBox1.Enabled = false; // Включён
            textBox2.Enabled = false; // Отключён
            textBox1.Text = "";
            textBox2.Text = "";
            textBox4.ReadOnly = true;
            textBox4.Enabled = false;
            textBox4.Text = "0";
            textBox5.ReadOnly = true;
            textBox5.Enabled = false;
            textBox5.Text = "0";
            textBox6.ReadOnly = true;
            textBox6.Enabled = false;
            textBox6.Text = "0";
            textBox7.ReadOnly = true;
            textBox7.Enabled = false;
            textBox7.Text = "0";
            checkBox1.CheckState = CheckState.Unchecked;
            checkBox2.CheckState = CheckState.Unchecked;
            checkBox3.CheckState = CheckState.Unchecked;
            checkBox4.CheckState = CheckState.Unchecked;
            textBox1.Enabled = true;
            radioButton1.Checked = true;
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox3.Checked)
            {
                textBox6.ReadOnly = false;
                textBox6.Enabled = true;
            }
            if (!checkBox3.Checked)
            {
                textBox6.ReadOnly = true;
                textBox6.Enabled = false;
                textBox6.Text = "0";
            }
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox4.Checked)
            {
                textBox7.ReadOnly = false;
                textBox7.Enabled = true;
            }
            if (!checkBox4.Checked)
            {
                textBox7.ReadOnly = true;
                textBox7.Enabled = false;
                textBox7.Text = "0";
            }
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            label11.Text = (int.Parse(textBox4.Text) * double.Parse(textBox8.Text) + int.Parse(textBox5.Text) * double.Parse(textBox9.Text) + int.Parse(textBox6.Text) * double.Parse(textBox10.Text) + int.Parse(textBox7.Text) * double.Parse(textBox11.Text)).ToString();
        }
    }
}
