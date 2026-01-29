using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrikupljanjePodatakaTermometra {
    class Measurement {
        public Measurement() { }
        public Measurement(object id, object value, object timestamp, object sensorName) {
            Id = (int)id;
            Value = Convert.ToDouble(value);
            Timestamp = Convert.ToDateTime(timestamp);
            SensorName = (string)sensorName;
        }
        public Measurement(double value, DateTime timestamp, string sensorName) {
            Value = value;
            Timestamp = timestamp;
            SensorName = sensorName;
        }
        public override string ToString() {
            return $"{SensorName}: {Value}°C @ {Timestamp}";
        }
        public int Id { get; set; }
        public double Value { get; set; }
        public DateTime Timestamp { get; set; }
        public string SensorName { get; set; }
    }
}
