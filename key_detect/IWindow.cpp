#include "IWindow.h"

LRESULT CALLBACK IWindow::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	IWindow* winPtr = (IWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
	if (!winPtr)
		return DefWindowProc(hwnd, message, wParam, lParam);
	else
		return winPtr->MsgProc(hwnd, message, wParam, lParam);
}