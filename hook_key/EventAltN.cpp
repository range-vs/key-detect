#include "EventAltN.h"

int EventAltN::run(SmartEventData gh)
{
	if (GetAsyncKeyState(VK_MENU) & 0x8000)
	{
		data = L"Нажата комбинация alt + N\n";
		data += gh->isAltN() ? L"Правый enter вновь соответствует своему значению\n" : L"Правый enter изменил своё значение на 'н'\n";
		gh->switchAltN();
		time_t seconds = time(NULL);
		tm timeinfo;
		localtime_s(&timeinfo, &seconds);
		char buf[500];
		asctime_s(buf, 500, &timeinfo);
		date = wstring(buf, buf + 500) + L"\n\n";
		gh->getWindow()->addNotify(data, L"Уведомление", NIM_MODIFY);
	}
	return 0;
}

wstring EventAltN::createData()
{
	return data + date;
}
