using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;

namespace NotesApp {
    class Notes {
        public static List<Note> GetNotes() {
            List<Note> notes = new List<Note>();
            string query = "SELECT * FROM Notes ORDER BY Name";

            using (SqlConnection sqlConnection = new SqlConnection(Baza.KonekcijskiString())) {
                SqlDataAdapter adapter = new SqlDataAdapter(query, sqlConnection);
                DataSet ds = new DataSet();
                adapter.Fill(ds);
                foreach (DataRow redak in ds.Tables[0].Rows) {
                    notes.Add(new Note(
                        redak["Id"],
                        redak["Content"],
                        redak["Name"]
                    ));
                }
            }
            return notes;
        }

        public static bool AddNote(Note note) {
            string query = "INSERT INTO Notes (Content, Name) VALUES (@Content, @Name)";

            using (SqlConnection sqlConnection = new SqlConnection(Baza.KonekcijskiString())) {
                using (SqlCommand command = new SqlCommand(query, sqlConnection)) {
                    command.Parameters.AddWithValue("@Content", note.Content);
                    command.Parameters.AddWithValue("@Name", note.Name);

                    sqlConnection.Open();
                    int result = command.ExecuteNonQuery();
                    if (result < 0) {
                        return false;
                    }
                }
            }
            return true;

        }

        public static Note GetNote(int id) {
            Note note = new Note();

            // TODO:

            return note;
        }

        public static bool UpdateNote(Note note, string newContent) {
            // TODO: 
            return true;
        }
    }
}
