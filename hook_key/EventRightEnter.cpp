#include "EventRightEnter.h"

int EventRightEvent::run(SmartEventData gh)
{
	if (gh->isAltN())
	{
		INPUT ip;
		ip.type = INPUT_KEYBOARD;
		ip.ki.time = 0;
		ip.ki.wVk = 0x59; // Н/Y
		ip.ki.dwFlags = 0;
		SendInput(1, &ip, sizeof(INPUT)); // отправляет нажатие клавиши в верх очереди сообщений
		return 1;
	}
	return 0;
}

wstring EventRightEvent::createData()
{
	if(isData)
		return L"Нажат 'enter'(н)\n";
	return L"";
}
