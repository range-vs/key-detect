#include "EventAltO.h"

int EventAltP::run(SmartEventData gh)
{
	if (GetAsyncKeyState(VK_MENU) & 0x8000)
	{
		data = L"Нажата комбинация alt + P\n";
		data += gh->isAltP() ? L"Правый \"ctrl\" вновь соответствует своему значению\n" : L"Правый \"ctrl\" изменил своё значение на \"m/ь\"\n";
		gh->switchAltP();
		time_t seconds = time(NULL);
		tm timeinfo;
		localtime_s(&timeinfo, &seconds);
		char buf[500];
		asctime_s(buf, 500, &timeinfo);
		date = wstring(buf, buf + strlen(buf)) + L"\n";
		gh->getWindow()->addNotify(data, L"Уведомление", NIM_MODIFY);
	}
	return 0;
}

wstring EventAltP::createData()
{
	return data + date;
}
