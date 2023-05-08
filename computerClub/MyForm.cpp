#include "MyForm.h"
#include <Windows.h>
#include <cstdlib>
using namespace computerClub;
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm form;
	Application::Run(% form);
}