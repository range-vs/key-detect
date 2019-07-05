#include "SaveFileDialog.h"

SaveFileDialog::SaveFileDialog(HWND hwnd):hwnd(hwnd)
{ 
	dllComDlg.reset(new LoaderDll(L"ComDlg32.DLL"));
}

bool SaveFileDialog::action()
{
	GetModuleFileName(NULL, defaultCatalog, MAX_PATH + 1);
	pathExe = defaultCatalog;
	pathExe = pathExe.substr(0, pathExe.find_last_of(L"\\") + 1); // в конце обязательно слеш!

	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = L"Text(*.txt)\0*.txt\0\0";
	ofn.lpstrTitle = L"Save log file...";
	ofn.lpstrInitialDir = pathExe.c_str();
	ofn.nMaxFileTitle = 0;
	ofn.lpstrDefExt = szDefExt;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT;

	bool result = GetSaveFileName(&ofn);
	return result;
}

wstring SaveFileDialog::getPath()
{
	return szFile;
}
