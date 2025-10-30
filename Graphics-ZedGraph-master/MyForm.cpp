#include "MyForm.h"
#include <clocale>

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	setlocale(LC_ALL, "Russian");
	//system("chcp 1251");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Graph::MyForm form;
	Application::Run(%form);
}
