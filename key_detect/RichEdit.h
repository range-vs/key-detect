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
	RichEdit():OldWndProc(NULL), hwnd(NULL), hglbTextCopyBuf(NULL), contextMenu(NULL){}
	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM) override;
	void init(HWND, HINSTANCE) override;
	void addData(SmartConsoleData) override;
	HWND& getDescriptor() override;
};