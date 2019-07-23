#include "Controller.h"
#include "ParseArgs.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPInst, char* line, int show)
{
	MSG result = { 0 };
	SmartController work;
	SmartParseArgs args;
	try
	{
		args.reset(new ParseArgs(line));
		work.reset(new Controller(hInstance));
		work->init();
		result = work->run(args->getValue(L"ms"));
	}
	catch (wstring& ex)
	{
		MessageBox(NULL, ex.c_str(), L"Error!", MB_OK);
		work->errorClear();
	}
	return result.wParam;
}