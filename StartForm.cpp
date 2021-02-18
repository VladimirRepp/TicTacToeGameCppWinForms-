#include "StartForm.h"
#include "GameForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TicTacToegame::StartForm form;
	Application::Run(% form);
}

TicTacToegame::StartForm::StartForm(void)
{
	InitializeComponent();

	//������������� ������
	sound = gcnew System::Media::SoundPlayer("..\\Resources\\1.wav");
}

System::Void TicTacToegame::StartForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	sound->Play();//��������������� �����
	MessageBox::Show("���� \"��������-������\".", "���������� � ���������!");
}

System::Void TicTacToegame::StartForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	sound->Play();//��������������� �����
	Application::Exit();
}

System::Void TicTacToegame::StartForm::buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	sound->Play();//��������������� �����

	//��������� ������
	int indexGameMode = listBoxGameMode->SelectedIndex;
	if (indexGameMode == -1) {
		MessageBox::Show("�������� ����� ����!", "��������!");
		return;
	}

	int size;
	size = Convert::ToInt32(numericUpDownSizeMap->Value);

	numericUpDownLength->Maximum = size;
	int length = Convert::ToInt32(numericUpDownLength->Value);

	//������� ����� 
	GameForm^ form = gcnew GameForm();
	form->rows = size;
	form->columns = size;
	form->length = length;
	form->selectedGameMode = indexGameMode;
	form->Show();
	this->Hide();
}