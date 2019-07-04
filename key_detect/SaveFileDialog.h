#pragma once

#include "LoaderDll.h"

class SaveFileDialog
{
	SmartLoaderDll dllComDlg;
	wchar_t szFile[MAX_PATH] = { L'\0' };
	wchar_t defaultCatalog[MAX_PATH];
	wchar_t szDefExt[MAX_PATH] = { L"txt" };
	wstring pathExe;
	HWND hwnd;

public:
	SaveFileDialog(HWND hwnd);
	bool action();
	wstring getPath();
};