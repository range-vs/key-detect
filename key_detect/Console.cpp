#include "Console.h"

LRESULT Console::MsgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_RBUTTONMENU:
	{
		switch (lParam)
		{
		case WM_RBUTTONUP:
		{
			// активизирует окно
			SetForegroundWindow(hwnd);
			// Извлекаем координаты курсора мыши
			POINT pt;
			GetCursorPos(&pt); // т.к. кооринаты не передаются в функцию, берём напрямую
			// Отображаем меню
			TrackPopupMenu(contextMenu,TPM_RIGHTBUTTON |TPM_TOPALIGN |TPM_LEFTALIGN,pt.x,pt.y, 0, hwnd, NULL);
			break;
		}

		case WM_LBUTTONDBLCLK: 
		{
			ShowWindow(hwnd, SW_SHOW);
			ShowWindow(hwnd, SW_RESTORE);
			return 0;
		}

		default:
			break;
		}

		break;
	}

	case WM_SIZE:
	{
		RECT rect;
		GetClientRect(hwnd, &rect);
		WPARAM sizeEdit = MAKEWPARAM(rect.right - rect.left, rect.bottom - rect.top);
		for (auto control : controls)
		{
			SetWindowPos(control->getDescriptor(), HWND_TOP, rect.left, rect.top, rect.right, rect.bottom, SWP_DRAWFRAME);
			RedrawWindow(control->getDescriptor(), NULL, NULL, RDW_INTERNALPAINT);
		}

		switch (wParam)
		{
		case SIZE_MINIMIZED:
		{
			//addNotify("Свернуто", titleNotify, NIM_MODIFY);
			ShowWindow(hwnd, SW_HIDE);
			break;
		}

		case SIZE_RESTORED:
		{
			//addNotify("Развёрнуто", titleNotify, NIM_MODIFY);
			break;
		}
		}

		break;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case CONSOLE_MENU_RESTORE:
		{
			ShowWindow(hwnd, SW_SHOW);
			ShowWindow(hwnd, SW_RESTORE);
			break;
		}

		case CONSOLE_MENU_EXIT: 
		{
			PostMessage(hwnd, WM_CLOSE, lParam, wParam);
			break;
		}

		case CONSOLE_MENU_ABOUT:
		{
			actionsMenu[CONSOLE_MENU_ABOUT]();
			break;
		}

		case CONSOLE_MAINMENU_SAVELOG:
		{
			actionsMenu[CONSOLE_MAINMENU_SAVELOG]();
			break;
		}

		case CONSOLE_MAINMENU_CLEARLOG:
		{
			actionsMenu[CONSOLE_MAINMENU_CLEARLOG]();
			break;
		}

		default: break;
		}
		break;
	}

	case WM_DESTROY:
	{
		addNotify(L"Завершено", titleNotify, NIM_DELETE);
		PostQuitMessage(0);
		DestroyMenu(contextMenu);
		break;
	}


	default:
	{
		if (message == msgTaskbarRestart)
			addNotify(L"Запущен", titleNotify, NIM_ADD);
		break;
	}

	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void Console::init(HWND main, HINSTANCE hInst)
{
	WNDCLASS wc = {
		CS_VREDRAW | CS_HREDRAW | CS_NOCLOSE,
		(WNDPROC)WndProc,
		0,
		0,
		hInst,
		LoadIcon(hInst,MAKEINTRESOURCE(MAIN_ICON_APP)),
		LoadCursor(hInst,IDC_ARROW),
		GetSysColorBrush(COLOR_WINDOW),
		NULL,
		L"wndclass" };
	RegisterClass(&wc);
	mainMenu = CreateMenu();
	AppendMenu(mainMenu, MF_STRING, CONSOLE_MAINMENU_SAVELOG, L"Save log");
	AppendMenu(mainMenu, MF_STRING, CONSOLE_MAINMENU_CLEARLOG, L"Clear log");
	hwnd = CreateWindow(L"wndclass", L"title", WS_OVERLAPPEDWINDOW, 64, 64, 640, 480, 0, mainMenu, hInst, 0);
	SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)this);
	contextMenu = CreatePopupMenu();
	AppendMenu(contextMenu, MF_STRING, CONSOLE_MENU_RESTORE, L"Restore");
	AppendMenu(contextMenu, MF_STRING, CONSOLE_MENU_ABOUT, L"About");
	AppendMenu(contextMenu, MF_SEPARATOR, -1, L"");
	AppendMenu(contextMenu, MF_STRING, CONSOLE_MENU_EXIT, L"Exit");

	addNotify(L"Запущен", titleNotify, NIM_ADD);

	msgTaskbarRestart = RegisterWindowMessage(L"TaskbarCreated");
}

void Console::addNotify(const wstring& message, const wstring& title, UINT type)
{
	Notify notify(hwnd, message, title, type);
}

void Console::addControl(SmartControl c)
{
	controls.push_back(c);
}

void Console::mailingEvents(SmartConsoleData data)
{
	for (auto& c : controls)
		c->addData(data);
}

HWND& Console::getDescriptor()
{
	return hwnd;
}

void Console::addMenuAction(int idMenu, function<void()> actionMenu)
{
	actionsMenu.insert({ idMenu, actionMenu });
}
