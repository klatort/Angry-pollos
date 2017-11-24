#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]//leave this as is
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew WindowsForms::MyForm);
}