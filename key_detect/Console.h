#pragma once

#include "IHookWindow.h"
#include "types.h"
#include "Notify.h"
#include "resource.h"
#include "Thunk.h"

class Console : public IHookWindow
{
	vector<SmartControl> controls;
	HWND hwnd;
	UINT msgTaskbarRestart;
	HMENU contextMenu;
	HMENU mainMenu;
	wstring titleNotify;
	map<int, function<void()>> actionsMenu;
	SmartThunkCreator callbackWndProc;

public:
	Console():msgTaskbarRestart(-1), titleNotify(L"Осведомитель нажатий системных клавиш"), mainMenu(NULL), contextMenu(NULL), hwnd(NULL){}
	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
	void init(HWND main, HINSTANCE hInst);
	void addNotify(const wstring& message, const wstring& title, UINT type);
	void addControl(SmartControl);
	void mailingEvents(SmartConsoleData);
	void addMenuAction(int, function<void()>);
	HWND& getDescriptor();
};