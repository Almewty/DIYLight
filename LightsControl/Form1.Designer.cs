namespace LightsControl
{
    partial class Form1
    {
        /// <summary>
        /// Erforderliche Designervariable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Verwendete Ressourcen bereinigen.
        /// </summary>
        /// <param name="disposing">True, wenn verwaltete Ressourcen gelöscht werden sollen; andernfalls False.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Vom Windows Form-Designer generierter Code

        /// <summary>
        /// Erforderliche Methode für die Designerunterstützung.
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            this._btnStart = new System.Windows.Forms.Button();
            this._btnStop = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this._numLeft = new System.Windows.Forms.NumericUpDown();
            this._numTop = new System.Windows.Forms.NumericUpDown();
            this._numRight = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this._resolutionLabel = new System.Windows.Forms.Label();
            this._chkColorBoost = new System.Windows.Forms.CheckBox();
            this._chkMinColor = new System.Windows.Forms.CheckBox();
            ((System.ComponentModel.ISupportInitialize)(this._numLeft)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this._numTop)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this._numRight)).BeginInit();
            this.SuspendLayout();
            // 
            // _btnStart
            // 
            this._btnStart.Location = new System.Drawing.Point(12, 127);
            this._btnStart.Name = "_btnStart";
            this._btnStart.Size = new System.Drawing.Size(75, 23);
            this._btnStart.TabIndex = 0;
            this._btnStart.Text = "Start";
            this._btnStart.UseVisualStyleBackColor = true;
            this._btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // _btnStop
            // 
            this._btnStop.Enabled = false;
            this._btnStop.Location = new System.Drawing.Point(93, 127);
            this._btnStop.Name = "_btnStop";
            this._btnStop.Size = new System.Drawing.Size(75, 23);
            this._btnStop.TabIndex = 1;
            this._btnStop.Text = "Stop";
            this._btnStop.UseVisualStyleBackColor = true;
            this._btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(25, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Left";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 41);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(26, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Top";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 67);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(32, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Right";
            // 
            // _numLeft
            // 
            this._numLeft.Location = new System.Drawing.Point(50, 13);
            this._numLeft.Name = "_numLeft";
            this._numLeft.Size = new System.Drawing.Size(118, 20);
            this._numLeft.TabIndex = 4;
            // 
            // _numTop
            // 
            this._numTop.Location = new System.Drawing.Point(50, 39);
            this._numTop.Name = "_numTop";
            this._numTop.Size = new System.Drawing.Size(118, 20);
            this._numTop.TabIndex = 4;
            // 
            // _numRight
            // 
            this._numRight.Location = new System.Drawing.Point(50, 65);
            this._numRight.Name = "_numRight";
            this._numRight.Size = new System.Drawing.Size(118, 20);
            this._numRight.TabIndex = 4;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 88);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(60, 13);
            this.label4.TabIndex = 5;
            this.label4.Text = "Resolution:";
            // 
            // _resolutionLabel
            // 
            this._resolutionLabel.AutoSize = true;
            this._resolutionLabel.Location = new System.Drawing.Point(78, 88);
            this._resolutionLabel.Name = "_resolutionLabel";
            this._resolutionLabel.Size = new System.Drawing.Size(35, 13);
            this._resolutionLabel.TabIndex = 6;
            this._resolutionLabel.Text = "label5";
            // 
            // _chkColorBoost
            // 
            this._chkColorBoost.AutoSize = true;
            this._chkColorBoost.Checked = true;
            this._chkColorBoost.CheckState = System.Windows.Forms.CheckState.Checked;
            this._chkColorBoost.Location = new System.Drawing.Point(12, 104);
            this._chkColorBoost.Name = "_chkColorBoost";
            this._chkColorBoost.Size = new System.Drawing.Size(79, 17);
            this._chkColorBoost.TabIndex = 7;
            this._chkColorBoost.Text = "Color boost";
            this._chkColorBoost.UseVisualStyleBackColor = true;
            this._chkColorBoost.CheckedChanged += new System.EventHandler(this._chkColorBoost_CheckedChanged);
            // 
            // _chkMinColor
            // 
            this._chkMinColor.AutoSize = true;
            this._chkMinColor.Checked = true;
            this._chkMinColor.CheckState = System.Windows.Forms.CheckState.Checked;
            this._chkMinColor.Location = new System.Drawing.Point(97, 104);
            this._chkMinColor.Name = "_chkMinColor";
            this._chkMinColor.Size = new System.Drawing.Size(69, 17);
            this._chkMinColor.TabIndex = 7;
            this._chkMinColor.Text = "Min color";
            this._chkMinColor.UseVisualStyleBackColor = true;
            this._chkMinColor.CheckedChanged += new System.EventHandler(this._chkMinColor_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(179, 160);
            this.Controls.Add(this._chkMinColor);
            this.Controls.Add(this._chkColorBoost);
            this.Controls.Add(this._resolutionLabel);
            this.Controls.Add(this.label4);
            this.Controls.Add(this._numRight);
            this.Controls.Add(this._numTop);
            this.Controls.Add(this._numLeft);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this._btnStop);
            this.Controls.Add(this._btnStart);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this._numLeft)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this._numTop)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this._numRight)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button _btnStop;
        private System.Windows.Forms.Button _btnStart;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label _resolutionLabel;
        private System.Windows.Forms.NumericUpDown _numRight;
        private System.Windows.Forms.NumericUpDown _numTop;
        private System.Windows.Forms.NumericUpDown _numLeft;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.CheckBox _chkColorBoost;
        private System.Windows.Forms.CheckBox _chkMinColor;
    }
}

