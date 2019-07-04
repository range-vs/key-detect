#include "Notify.h"

Notify::Notify(const HWND& hwnd, const wstring& message, const wstring& title, UINT type)
{
	NOTIFYICONDATA nid;
	memset(&nid, 0, sizeof(NOTIFYICONDATA));
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = hwnd;
	nid.uID = 7;
	nid.uFlags = NIF_INFO | NIF_STATE | NIF_ICON | NIF_TIP | NIF_MESSAGE;
	nid.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(MAIN_ICON_APP));
	nid.uCallbackMessage = WM_RBUTTONMENU;
	wcscpy_s(nid.szInfo, message.c_str());
	//nid.dwState = NIS_HIDDEN;
	nid.dwInfoFlags = NIIF_NOSOUND; // красивый вывод, Отключаем звук уведомлений
	wcscpy_s(nid.szTip, title.c_str());
	Shell_NotifyIcon(type, &nid);
}
