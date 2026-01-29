using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PrikupljanjePodatakaTermometra {
    public partial class Form1 : Form {
        public Form1() {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e) {
            RefreshMeasurements();
        }

        private void btnNewMeasurement_Click(object sender, EventArgs e) {
            double value;
            if (double.TryParse(tbNewValue.Text, out value)) {
                Measurements.AddMeasurement(new Measurement(value, DateTime.Now, tbSensorName.Text));
                RefreshMeasurements();
            } else {
                MessageBox.Show("Unesite ispravnu vrijednost temperature.");
            }
        }

        private void RefreshMeasurements() {
            var measurements = Measurements.GetMeasurements();
            lbMeasurements.Items.Clear();
            foreach (var m in measurements.OrderByDescending(m => m.Timestamp)) {
                lbMeasurements.Items.Add(m);
            }
        }

        private void lbMeasurements_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
