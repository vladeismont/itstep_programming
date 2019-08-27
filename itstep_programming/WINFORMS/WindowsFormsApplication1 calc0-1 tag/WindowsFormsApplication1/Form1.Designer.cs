namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Digit1 = new System.Windows.Forms.Button();
            this.Plus = new System.Windows.Forms.Button();
            this.equally = new System.Windows.Forms.Button();
            this.Display = new System.Windows.Forms.TextBox();
            this.Digit0 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Digit1
            // 
            this.Digit1.Location = new System.Drawing.Point(156, 72);
            this.Digit1.Name = "Digit1";
            this.Digit1.Size = new System.Drawing.Size(44, 39);
            this.Digit1.TabIndex = 1;
            this.Digit1.Tag = "1";
            this.Digit1.Text = "1";
            this.Digit1.UseVisualStyleBackColor = true;
            this.Digit1.Click += new System.EventHandler(this.DigitButton_Click);
            // 
            // Plus
            // 
            this.Plus.Location = new System.Drawing.Point(82, 143);
            this.Plus.Name = "Plus";
            this.Plus.Size = new System.Drawing.Size(44, 39);
            this.Plus.TabIndex = 2;
            this.Plus.Text = "+";
            this.Plus.UseVisualStyleBackColor = true;
            // 
            // equally
            // 
            this.equally.Location = new System.Drawing.Point(156, 143);
            this.equally.Name = "equally";
            this.equally.Size = new System.Drawing.Size(44, 39);
            this.equally.TabIndex = 3;
            this.equally.Text = "=";
            this.equally.UseVisualStyleBackColor = true;
            // 
            // Display
            // 
            this.Display.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Display.ForeColor = System.Drawing.SystemColors.WindowText;
            this.Display.Location = new System.Drawing.Point(82, 12);
            this.Display.Name = "Display";
            this.Display.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.Display.Size = new System.Drawing.Size(118, 32);
            this.Display.TabIndex = 4;
            // 
            // Digit0
            // 
            this.Digit0.Location = new System.Drawing.Point(82, 72);
            this.Digit0.Name = "Digit0";
            this.Digit0.Size = new System.Drawing.Size(44, 39);
            this.Digit0.TabIndex = 5;
            this.Digit0.Tag = "0";
            this.Digit0.Text = "0";
            this.Digit0.UseVisualStyleBackColor = true;
            this.Digit0.Click += new System.EventHandler(this.DigitButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.Digit0);
            this.Controls.Add(this.Display);
            this.Controls.Add(this.equally);
            this.Controls.Add(this.Plus);
            this.Controls.Add(this.Digit1);
            this.Name = "Form1";
            this.Text = "Calculator";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Digit1;
        private System.Windows.Forms.Button Plus;
        private System.Windows.Forms.Button equally;
        private System.Windows.Forms.TextBox Display;
        private System.Windows.Forms.Button Digit0;
    }
}

