#include "EventAltO.h"

int EventAltO::run(SmartEventData gh)
{
	if (GetAsyncKeyState(VK_MENU) & 0x8000)
	{
		data = L"Нажата комбинация alt + O\n";
		data += gh->isAltO() ? L"\nПравый \"+\" вновь соответствует своему значению\n" : L"\nПравый \"+\" изменил своё значение на \"осв\"\n";
		gh->switchAltO();
		time_t seconds = time(NULL);
		tm timeinfo;
		localtime_s(&timeinfo, &seconds);
		char buf[500];
		asctime_s(buf, 500, &timeinfo);
		//data += buf;
		gh->getWindow()->addNotify(data, L"Уведомление", NIM_MODIFY);
	}
	return 0;
}

wstring EventAltO::createData()
{
	return data;
}
