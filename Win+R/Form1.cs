using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Input;
using GlobalHotKey;

namespace System
{
    public partial class Form : Windows.Forms.Form
    {
        HotKeyManager keyManager;

        public Form()
        {
            InitializeComponent();
            keyManager = new HotKeyManager();
            //Hot key: Shift + F
            keyManager.Register(Key.F, Windows.Input.ModifierKeys.Shift);
            keyManager.KeyPressed += HotKeyPressed;
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            try
            {
                process.StartInfo = new ProcessStartInfo(textBox.Text);
                process.Start();
                this.Hide();
                process.WaitForExit();
                this.Show();
            }
            catch (System.ComponentModel.Win32Exception)
            {
                MessageBox.Show("Не удается найти указанный файл.", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch(System.InvalidOperationException)
            {
                this.Show();
            }
        }

        private void buttonOpen_Click(object sender, EventArgs e)
        {
            OpenFileDialog fileDialog = new OpenFileDialog();
            fileDialog.Filter = "Программы | *.exe |Все файлы | *.*";
            DialogResult result = fileDialog.ShowDialog();
            if(result == DialogResult.OK)
            {
                textBox.Text = fileDialog.FileName;
            }
        }

        private void HotKeyPressed(object sender, KeyPressedEventArgs e)
        {
            if (e.HotKey.Key == Key.F)
            {
                this.Show();
            }                
        }

        private void Form_FormClosing(object sender, FormClosingEventArgs e)
        {
            keyManager.Dispose();
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Hide();
        }
    }
}
