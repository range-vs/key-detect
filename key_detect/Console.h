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
	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM) override;
	void init(HWND main, HINSTANCE hInst) override;
	void addNotify(const wstring& message, const wstring& title, UINT type) override;
	void addControl(SmartControl) override;
	void mailingEvents(SmartConsoleData) override;
	void addMenuAction(int, function<void()>) override;
	HWND& getDescriptor() override;
};