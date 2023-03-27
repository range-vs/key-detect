#include "RichEdit.h"

#include <algorithm>

LRESULT RichEdit::MsgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	case WM_CONTEXTMENU:
	{
		TrackPopupMenu(contextMenu, TPM_RIGHTBUTTON |
			TPM_TOPALIGN |
			TPM_LEFTALIGN,
			LOWORD(lParam),
			HIWORD(lParam), 0, hwnd, NULL);
		break;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			
		case RICH_MENU_COPY:
		{
			// количество символов
			CHARRANGE charRange;
			SendMessage(hwnd, EM_EXGETSEL, NULL, (LPARAM)&charRange);
			int size = (charRange.cpMax - charRange.cpMin) * 2 + 2;
			// получаем текст
			wstring buf; buf.resize(size);
			SendMessage(hwnd, EM_GETSELTEXT, NULL, (LPARAM)buf.c_str());
			// запись в буфер обмена
			hglbTextCopyBuf = GlobalAlloc(GMEM_MOVEABLE, buf.size());
			memcpy(GlobalLock(hglbTextCopyBuf), buf.c_str(), buf.size());
			GlobalUnlock(hglbTextCopyBuf);
			OpenClipboard(0);
			EmptyClipboard();
			SetClipboardData(CF_UNICODETEXT, hglbTextCopyBuf);
			CloseClipboard();

			break;
		}

		case RICH_MENU_SELECTALL: 
		{
			SendMessage(hwnd, EM_SETSEL, 0, -1);
			break;
		}

		default: break;
		}
		break;
	}

	case WM_SETCURSOR:
	{
		SetCursor(LoadCursor(NULL, IDC_ARROW));
		return TRUE;
	}

	case WM_CHAR: // read only rich edit
	{
		return false;
	}

	case WM_KEYDOWN: // read only rich edit
	{
		return false;
	}

	case WM_DESTROY:
	{
		DestroyMenu(contextMenu);
		if (hglbTextCopyBuf != NULL)
			GlobalFree(hglbTextCopyBuf);
		return 0;
	}

	}
	return CallWindowProc(OldWndProc, hwnd, message, wParam, lParam);
}

void RichEdit::init(HWND main, HINSTANCE hInst)
{
	dllRichEdit.reset(new LoaderDll(L"Riched20.dll"));
	hglbTextCopyBuf = NULL;
	RECT rect;
	GetClientRect(main, &rect);
	// create window
	hwnd = CreateWindowEx(NULL, L"RICHEDIT20W", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_VSCROLL, rect.left, rect.top, rect.right, rect.bottom, main, 0, hInst, 0);
	// change wnd proc
	callbackWndProc.reset(new ThunkCreator());
	callbackWndProc->createNonStaticCallbackFunction(this, &RichEdit::MsgProc);
	OldWndProc = (WNDPROC)SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)callbackWndProc->getCallbackMethod());
	// change font
	HFONT fnt = CreateFont(16, 0, 0, 0, 1000, 0, 0, 0, ANSI_CHARSET, 1000, 0, 0, 0, L"Times New Roman");
	SendMessage(hwnd, WM_SETFONT, (WPARAM)fnt, TRUE);
	// change font color
	CHARFORMAT2 cf;
	COLORREF color = RGB(255, 255, 255);
	cf.dwMask = CFM_COLOR;
	cf.crTextColor = color;
	cf.cbSize = sizeof(CHARFORMAT2);
	cf.dwEffects = 0;
	SendMessage(hwnd, EM_SETCHARFORMAT, SCF_DEFAULT, (LPARAM)& cf);
	// change background color
	SendMessage(hwnd, EM_SETBKGNDCOLOR, 0, RGB(0, 0, 0));
	// create context menu
	contextMenu = CreatePopupMenu();
	AppendMenu(contextMenu, MF_STRING, RICH_MENU_COPY, L"Copy");
	AppendMenu(contextMenu, MF_SEPARATOR, -1, L"");
	AppendMenu(contextMenu, MF_STRING, RICH_MENU_SELECTALL, L"Select all");
	// disable drag drop text
	RevokeDragDrop(hwnd);
}

void RichEdit::addData(SmartConsoleData data)
{
	std::for_each(data->getStartNewData(), data->getData().end(), [this](const wstring& lpString)
		{
			int iLength = GetWindowTextLength(hwnd);
			SendMessage(hwnd, EM_SETSEL, iLength, iLength);
			SendMessage(hwnd, EM_REPLACESEL, 0, (LPARAM)lpString.c_str());
			SendMessage(hwnd, WM_VSCROLL, SB_BOTTOM, (LPARAM)NULL);
		});
}

HWND& RichEdit::getDescriptor()
{
	return hwnd;
}
