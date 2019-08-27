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

namespace WindowsFormsApplication6 {
    public partial class Form1 : Form {

        DbConnection connection;
        DbDataAdapter adapter;
        public Form1() {
            InitializeComponent();

            connection = new SqlConnection();
            connection.ConnectionString = @"Data Source=A201PCPREPOD\A1PREPOD;" +
                    "Initial Catalog=PhoneBook;" +
                    "Integrated Security=yes";

            adapter = new SqlDataAdapter();

            DbCommand select = new SqlCommand();
            select.Connection = connection;
            select.CommandText = "Select * from Countries";
            adapter.SelectCommand = select;

            //DbCommand insert = new SqlCommand();
            //insert.Connection = connection;
            //insert.CommandText = "insert into Countries values(@cn)";
            //DbParameter countryName;
            //countryName = new SqlParameter("cn", SqlDbType.NVarChar, 20);
            //countryName.SourceColumn = "CountryName";
            //insert.Parameters.Add(countryName);
            //adapter.InsertCommand = insert;

            //DbCommand update = new SqlCommand();
            //update.Connection = connection;
            //update.CommandText = "update Countries set CountryName=@cn Where IdCountry=@id";
            //DbParameter upCountryName, upId;
            //upCountryName = new SqlParameter("cn", SqlDbType.NVarChar, 20);
            //upCountryName.SourceColumn = "CountryName";
            //update.Parameters.Add(upCountryName);
            //upId = new SqlParameter("id", SqlDbType.TinyInt, 1);
            //upId.SourceColumn = "IdCountry";
            //update.Parameters.Add(upId);
            //adapter.UpdateCommand = update;

            SqlCommandBuilder builder = new SqlCommandBuilder((SqlDataAdapter)adapter);
            adapter.InsertCommand = builder.GetInsertCommand();
            adapter.UpdateCommand = builder.GetUpdateCommand();
            adapter.DeleteCommand = builder.GetDeleteCommand();
            
        }

        private void button1_Click(object sender, EventArgs e) {
            getData();
        }

        public void getData() {
            dataSet1.Clear();
            adapter.Fill(dataSet1);
            dataGridView1.DataSource = dataSet1.Tables[0];  
        }

        private void button2_Click(object sender, EventArgs e) {
            adapter.Update(dataSet1);
            getData();
        }

        private void button3_Click(object sender, EventArgs e) {
            DataRow newRow = dataSet1.Tables[0].NewRow();
            newRow["CountryName"] = "LLLLLLL";
            dataSet1.Tables[0].Rows.Add(newRow);
            adapter.Update(dataSet1);
            getData();

        }
    }
}
