using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Common;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;

namespace WindowsFormsApplication6 {
    
    
    public class DB2 {
        
        
        private DbDataAdapter adapter;
        private DbDataAdapter countriesAdapter;

        DataSet dataSet2 = new DataSet();
        DataSet setCountries = new DataSet();

        protected static DbConnection connection;

        public DB2( string dataSource, string initial ) {
            if (connection is DbConnection) {
                return;
            }
            connection = new SqlConnection();
            var connectionString =
                ConfigurationManager.ConnectionStrings["MyConfig"].ConnectionString;
            connection.ConnectionString = connectionString;

            


            // -------------------------------------------------------------------
            DbCommand select = new SqlCommand();
            countriesAdapter = new SqlDataAdapter();
            select.Connection = connection;
            select.CommandText = "Select * from Countries";
            countriesAdapter.SelectCommand = select;

            SqlCommandBuilder builder = new SqlCommandBuilder((SqlDataAdapter)countriesAdapter);
            countriesAdapter.InsertCommand = builder.GetInsertCommand();
            countriesAdapter.UpdateCommand = builder.GetUpdateCommand();
            countriesAdapter.DeleteCommand = builder.GetDeleteCommand();
        }

        public DataTable getCountries() {
            setCountries.Clear();
            countriesAdapter.Fill(setCountries);
            return setCountries.Tables[0];
        }

        //public DataSet getSetData() {
        //    //dataSet2.Clear();
        //    //adapter.Fill(dataSet2);
        //    //return dataSet2;
        //}

        public DataTable getTableData(int countryId) {
            adapter = new SqlDataAdapter();

            DbCommand select = new SqlCommand();
            select.Connection = connection;
            select.CommandText =
                "Select sb.IdSubscriber, sb.LastName from Subscribers as sb" +
                " JOIN Adress as ad ON sb.IdAdress = ad.IdAdress " +
                " Where ad.IdCountry=" + countryId.ToString();
            adapter.SelectCommand = select;

            //SqlCommandBuilder builder = new SqlCommandBuilder((SqlDataAdapter)adapter);
            //adapter.InsertCommand = builder.GetInsertCommand();
            //adapter.UpdateCommand = builder.GetUpdateCommand();
            //adapter.DeleteCommand = builder.GetDeleteCommand();
            
            dataSet2.Clear();
            adapter.Fill(dataSet2);
            return dataSet2.Tables[0];
        }

    }


}
