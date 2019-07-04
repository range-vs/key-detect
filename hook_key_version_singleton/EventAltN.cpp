#include "EventAltN.h"

int EventAltN::run()
{
	if (GetKeyState(160) & 0x80 || GetKeyState(161) & 0x80)
	{
		data = L"Нажата комбинация alt + N\n";
		data += GlobalHook::getInstance()->isAltN() ? L"\nПравый enter вновь соответствует своему значению\n" : L"\nПравый enter изменил своё значение на 'н'\n";
		GlobalHook::getInstance()->switchAltN();
		time_t seconds = time(NULL);
		tm timeinfo;
		localtime_s(&timeinfo, &seconds);
		char buf[500];
		asctime_s(buf, 500, &timeinfo);
		//data += buf;
		GlobalHook::getInstance()->getWindow()->addNotify(data, L"Уведомление", NIM_MODIFY);
	}
	return 0;
}

wstring EventAltN::createData()
{
	return data;
}
