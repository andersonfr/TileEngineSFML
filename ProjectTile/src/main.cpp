#include "App.h"
#include <Windows.h>

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	App app;
	
	try
	{
		app.StartApp();
	}
	catch (char* e)
	{
		MessageBoxA(NULL, e, "Exception Occured", MB_OK | MB_ICONERROR);
	}

	return 0;
}