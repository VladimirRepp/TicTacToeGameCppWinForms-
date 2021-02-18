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

	//Инициализация звуков
	sound = gcnew System::Media::SoundPlayer("..\\Resources\\1.wav");
}

System::Void TicTacToegame::StartForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	sound->Play();//воспроизведение звука
	MessageBox::Show("Игра \"Крестики-Нолики\".", "Информация о программе!");
}

System::Void TicTacToegame::StartForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	sound->Play();//воспроизведение звука
	Application::Exit();
}

System::Void TicTacToegame::StartForm::buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	sound->Play();//воспроизведение звука

	//Считываем данные
	int indexGameMode = listBoxGameMode->SelectedIndex;
	if (indexGameMode == -1) {
		MessageBox::Show("Выберите режим игры!", "Внимание!");
		return;
	}

	int size;
	size = Convert::ToInt32(numericUpDownSizeMap->Value);

	numericUpDownLength->Maximum = size;
	int length = Convert::ToInt32(numericUpDownLength->Value);

	//Создаем форму 
	GameForm^ form = gcnew GameForm();
	form->rows = size;
	form->columns = size;
	form->length = length;
	form->selectedGameMode = indexGameMode;
	form->Show();
	this->Hide();
}