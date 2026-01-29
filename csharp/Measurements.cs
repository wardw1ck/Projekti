using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;

namespace PrikupljanjePodatakaTermometra {
    class Measurements {
        public static List<Measurement> GetMeasurements() {
            List<Measurement> measurements = new List<Measurement>();
            string query = "SELECT * FROM Measurements ORDER BY Timestamp DESC";

            using (SqlConnection sqlConnection = new SqlConnection(Baza.KonekcijskiString())) {
                SqlDataAdapter adapter = new SqlDataAdapter(query, sqlConnection);
                DataSet ds = new DataSet();
                adapter.Fill(ds);
                foreach (DataRow row in ds.Tables[0].Rows) {
                    measurements.Add(new Measurement(
                        row["Id"],
                        row["Value"],
                        row["Timestamp"],
                        row["SensorName"]
                    ));
                }
            }
            return measurements;
        }

        public static bool AddMeasurement(Measurement measurement) {
            string query = "INSERT INTO Measurements (Value, Timestamp, SensorName) VALUES (@Value, @Timestamp, @SensorName)";

            using (SqlConnection sqlConnection = new SqlConnection(Baza.KonekcijskiString())) {
                using (SqlCommand command = new SqlCommand(query, sqlConnection)) {
                    command.Parameters.AddWithValue("@Value", measurement.Value);
                    command.Parameters.AddWithValue("@Timestamp", measurement.Timestamp);
                    command.Parameters.AddWithValue("@SensorName", measurement.SensorName);

                    sqlConnection.Open();
                    int result = command.ExecuteNonQuery();
                    if (result < 0) {
                        return false;
                    }
                }
            }
            return true;
        }
    }
}
