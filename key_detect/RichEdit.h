#pragma once

#include "stdafx.h"
#include "IWindow.h"
#include "IControl.h"
#include "IData.h"
#include "LoaderDll.h"

class RichEdit;

using SmartRichEdit = shsmart_pointer<RichEdit>;

class RichEdit : public IControl
{
	HWND hwnd;
	SmartLoaderDll dllRichEdit;
	HMENU contextMenu;
	WNDPROC OldWndProc;
	HGLOBAL hglbTextCopyBuf;

public:
	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
	void init(HWND, HINSTANCE);
	void addData(SmartConsoleData);
	HWND& getDescriptor();
};