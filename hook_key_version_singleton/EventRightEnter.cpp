#include "EventRightEnter.h"

int EventRightEvent::run()
{
	if (GlobalHook::getInstance()->isAltN())
	{
		INPUT ip;
		ip.type = INPUT_KEYBOARD;
		ip.ki.time = 0;
		ip.ki.wVk = 0x59; // �/Y
		ip.ki.dwFlags = 0;
		SendInput(1, &ip, sizeof(INPUT)); // ���������� ������� ������� � ���� ������� ���������
		return 1;
	}
	return 0;
}

wstring EventRightEvent::createData()
{
	if(isData)
		return L"����� 'enter'(�)\n";
	return L"";
}
