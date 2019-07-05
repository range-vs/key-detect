#include "About.h"

About::About(const HWND& hwnd, const wstring& title, const wstring& message):hwnd(hwnd), title(title), message(message) { }

void About::show()
{
	MessageBox(hwnd, message.c_str(), title.c_str(), MB_OK);
}
