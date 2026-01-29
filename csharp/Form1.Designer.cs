namespace PrikupljanjePodatakaTermometra
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code


        private void InitializeComponent()
        {
            this.lbMeasurements = new System.Windows.Forms.ListBox();
            this.tbNewValue = new System.Windows.Forms.TextBox();
            this.tbSensorName = new System.Windows.Forms.TextBox();
            this.btnNewMeasurement = new System.Windows.Forms.Button();
            this.lblTemperature = new System.Windows.Forms.Label();
            this.lblSensorName = new System.Windows.Forms.Label();
            this.SuspendLayout();



            this.lbMeasurements.FormattingEnabled = true;
            this.lbMeasurements.ItemHeight = 16;
            this.lbMeasurements.Location = new System.Drawing.Point(31, 28);
            this.lbMeasurements.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.lbMeasurements.Name = "lbMeasurements";
            this.lbMeasurements.Size = new System.Drawing.Size(465, 564);
            this.lbMeasurements.TabIndex = 0;
            this.lbMeasurements.SelectedIndexChanged += new System.EventHandler(this.lbMeasurements_SelectedIndexChanged);



            this.tbNewValue.Location = new System.Drawing.Point(31, 601);
            this.tbNewValue.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tbNewValue.Name = "tbNewValue";
            this.tbNewValue.Size = new System.Drawing.Size(132, 22);
            this.tbNewValue.TabIndex = 1;



            this.tbSensorName.Location = new System.Drawing.Point(172, 601);
            this.tbSensorName.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tbSensorName.Name = "tbSensorName";
            this.tbSensorName.Size = new System.Drawing.Size(159, 22);
            this.tbSensorName.TabIndex = 2;



            this.btnNewMeasurement.Location = new System.Drawing.Point(340, 598);
            this.btnNewMeasurement.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnNewMeasurement.Name = "btnNewMeasurement";
            this.btnNewMeasurement.Size = new System.Drawing.Size(157, 28);
            this.btnNewMeasurement.TabIndex = 3;
            this.btnNewMeasurement.Text = "Dodaj mjerenje";
            this.btnNewMeasurement.UseVisualStyleBackColor = true;
            this.btnNewMeasurement.Click += new System.EventHandler(this.btnNewMeasurement_Click);



            this.lblTemperature.AutoSize = true;
            this.lblTemperature.Location = new System.Drawing.Point(31, 581);
            this.lblTemperature.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblTemperature.Name = "lblTemperature";
            this.lblTemperature.Size = new System.Drawing.Size(112, 16);
            this.lblTemperature.TabIndex = 4;
            this.lblTemperature.Text = "Temperatura (°C):";



            this.lblSensorName.AutoSize = true;
            this.lblSensorName.Location = new System.Drawing.Point(172, 581);
            this.lblSensorName.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblSensorName.Name = "lblSensorName";
            this.lblSensorName.Size = new System.Drawing.Size(95, 16);
            this.lblSensorName.TabIndex = 5;
            this.lblSensorName.Text = "Naziv senzora:";



            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1140, 709);
            this.Controls.Add(this.lblTemperature);
            this.Controls.Add(this.lblSensorName);
            this.Controls.Add(this.btnNewMeasurement);
            this.Controls.Add(this.tbSensorName);
            this.Controls.Add(this.tbNewValue);
            this.Controls.Add(this.lbMeasurements);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Forma";
            this.Text = "Prikupljanje podataka iz termometra";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox lbMeasurements;
        private System.Windows.Forms.TextBox tbNewValue;
        private System.Windows.Forms.TextBox tbSensorName;
        private System.Windows.Forms.Button btnNewMeasurement;
        private System.Windows.Forms.Label lblTemperature;
        private System.Windows.Forms.Label lblSensorName;
    }
}

