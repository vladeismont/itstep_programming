using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Common;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WindowsFormsApplication6;

namespace WindowsFormsApplication6 {
    
    public partial class Form1 : Form {

        public DB2 database;

       
        
        
        public Form1() {
            InitializeComponent();

            

            database = new DB2(@"A201PCPREPOD\A1PREPOD", "PhoneBook");

            DataSet setCountries = new DataSet();

            DataTable countriesTable = database.getCountries();
            cmbCountries.DataSource = countriesTable;
            cmbCountries.ValueMember = "IdCountry";
            cmbCountries.DisplayMember = "CountryName";

          


            
        }

        private void button1_Click(object sender, EventArgs e) {
            //connection = getDBInctance();
            getData();
        }

        public void getData() {
            //DataSet set = database.getSetData();
            dataGridView1.DataSource = 
                database.getTableData(Convert.ToInt32(cmbCountries.SelectedValue.ToString()));  
        }

        private void button2_Click(object sender, EventArgs e) {
            
            MessageBox.Show(cmbCountries.SelectedValue.ToString());
        }

        private void button3_Click(object sender, EventArgs e) {
            foreach (DataGridViewRow row in dataGridView1.SelectedRows) {                
                MessageBox.Show(row.Cells[0].Value.ToString() + " " +
                    row.Cells[1].Value.ToString());
            }

        }
    }
}
