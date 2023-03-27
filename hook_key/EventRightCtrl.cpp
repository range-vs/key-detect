#include "EventRightCtrl.h"

int EventRightCtrl::run(SmartEventData gh)
{
	if (gh->isAltN())
	{
		INPUT ip;
		ip.type = INPUT_KEYBOARD;
		ip.ki.time = 0;
		ip.ki.wVk = 0x4D; // m/ь
		ip.ki.dwFlags = 0;
		SendInput(1, &ip, sizeof(INPUT)); // отправляет нажатие клавиши в верх очереди сообщений
		isData = true;
		time_t seconds = time(NULL);
		tm timeinfo;
		localtime_s(&timeinfo, &seconds);
		char buf[500];
		asctime_s(buf, 500, &timeinfo);
		date = wstring(buf, buf + strlen(buf)) + L"\n";
		return 1;
	}
	isData = false;
	return 0;
}

wstring EventRightCtrl::createData()
{
	if(isData)
		return L"Нажат 'enter'(н)\n" + date;
	return L"";
}
