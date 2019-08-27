using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication5 {
    public partial class Form1 : Form {

        DataTable table;

        public Form1() {
            InitializeComponent();


            
                table = dataSet1.Tables.Add("table");
                table.Columns.Add("id", typeof(Int32));
                table.Columns.Add("name", typeof(String));
                table.Columns["name"].DefaultValue = "def";

                table.Constraints.Add("PK_table", table.Columns["id"], true);
                table.Columns["id"].AutoIncrement = true;
                table.Columns["id"].AutoIncrementSeed = 1;

            
                Constraint c = new UniqueConstraint(table.Columns["name"]);
                table.Constraints.Add(c);

                dataGridView1.DataSource = dataSet1;
                dataGridView1.DataMember = "table";
            
            

            
            
        }
        private void dataGridView1_DataError(object sender, DataGridViewDataErrorEventArgs anError) {
            if ((anError.Exception) is ConstraintException) {
                DataGridView view = (DataGridView)sender;
                view.Rows[anError.RowIndex].ErrorText = "an error";
                view.Rows[anError.RowIndex].Cells[anError.ColumnIndex].ErrorText = "an error";

                anError.ThrowException = false;
            }
        }


        private void button1_Click(object sender, EventArgs e) {
            //dataSet1.ReadXml("../../XMLFile1.xml");
            //dataGridView1.DataSource = dataSet1.Tables[0];

            dataSet1.WriteXml("../../XMLFile2.xml");
            table.Clear();
            table.Columns["id"].AutoIncrementStep = -1;
            table.Columns["id"].AutoIncrementStep = 1;
            
        }
    }
}
