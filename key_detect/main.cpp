#include "Controller.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPInst, char* line, int show)
{
	MSG result = { 0 };
	SmartController work;
	try
	{
		work.reset(new Controller(hInstance));
		work->init();
		result = work->run();
	}
	catch (wstring& ex)
	{
		MessageBox(NULL, ex.c_str(), L"Error!", MB_OK);
		work->errorClear();
	}
	return result.wParam;
}