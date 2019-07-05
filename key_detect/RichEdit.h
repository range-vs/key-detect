#pragma once

#include "stdafx.h"
#include "IWindow.h"
#include "IControl.h"
#include "IData.h"
#include "LoaderDll.h"
#include "Thunk.h"

class RichEdit;

using SmartRichEdit = shsmart_pointer<RichEdit>;

class RichEdit : public IControl
{
	HWND hwnd;
	SmartLoaderDll dllRichEdit;
	HMENU contextMenu;
	WNDPROC OldWndProc;
	HGLOBAL hglbTextCopyBuf;
	SmartThunkCreator callbackWndProc;

public:
	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
	void init(HWND, HINSTANCE);
	void addData(SmartConsoleData);
	HWND& getDescriptor();
};