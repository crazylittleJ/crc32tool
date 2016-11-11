#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	crc32cal_Tool::MyForm form;
	Application::Run(%form);
}


System::Void crc32cal_Tool::MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ currentPath;
	char* path;
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

	// Get the current working directory: 
	if ((path = _getcwd(NULL, 0)) == NULL)
		perror("_getcwd error");
	currentPath = gcnew String(path);
	openFileDialog1->InitialDirectory = currentPath;
	openFileDialog1->Filter = "bin files (*.bin)|*.bin";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->textBox1->Text = openFileDialog1->FileName;
		this->binPathA = this->textBox1->Text;
		//char* a = (char*)(void*)Marshal::StringToHGlobalAnsi(this->textBox1->Text);
	}
}

System::Void crc32cal_Tool::MyForm::button2_Click(System::Object^  sender, System::EventArgs^  e) {
	char** tempArgv;
	int x;
	char str[1080];
	char strTemp[100];
	char *path;
	String^ msg;
	uint32_t tempCRC;
	tempArgv = new char*[2];


	tempArgv[0] = "getCRC";
	tempArgv[1] = (char*)(void*)Marshal::StringToHGlobalAnsi(this->textBox1->Text);
	x = strcmp(tempArgv[1], "");

	if (x) {


		// Get the current working directory: 
		if ((path = _getcwd(NULL, 0)) == NULL)
			perror("_getcwd error");

		if (!this->_crc32->main_getCrc(2, tempArgv))
		{
			this->richTextBox1->Text = L"OK!";
			strcpy_s(str, path);
			//strcat_s(str, "\\default.bin");
			strcat_s(str, " -> Here's your current directory!!");
			strcat_s(str, "\n\r");
			tempCRC = _crc32->cChecksum[0];
			sprintf_s(strTemp, "Checksum(Hex) : 0x%04X \n\r Checksum(Decimal) : %u", _crc32->cChecksum[0],tempCRC);
			strcat_s(str, strTemp);
			strcat_s(str, "\n\r");
			sprintf_s(strTemp, "bytes : %d ", _crc32->bytesAmount);
			strcat_s(str, strTemp);
			msg = gcnew String(str);
			MessageBox::Show(msg,
				L"Done", MessageBoxButtons::OK,
				MessageBoxIcon::Information);
		}
		else {
			this->richTextBox1->Text = L"Error!";
			MessageBox::Show(L"We encounter something trouble during fetching CRC value.",
				L"Error", MessageBoxButtons::OK,
				MessageBoxIcon::Information);
		}
		delete[] tempArgv;
	}
	else {
		MessageBox::Show(L"Please select suitable binary files!",
			L"Error", MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	}
}