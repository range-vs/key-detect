#include "EventNumLock.h"

int EventNumLock::run(SmartEventData gh)
{
	data = L"Нажата клавиша Num Lock\n";
	if ((GetKeyState(VK_NUMLOCK) && 1) == 0)
		data += L"Клавиша активирована\n";
	else
		data += L"Клавиша деактивирована\n";
	time_t seconds = time(NULL);
	tm timeinfo;
	localtime_s(&timeinfo, &seconds);
	char buf[500];
	asctime_s(buf, 500, &timeinfo);
	date = wstring(buf, buf + 500) + L"\n\n";
	gh->getWindow()->addNotify(data, L"Уведомление", NIM_MODIFY);
	return 0;
}

wstring EventNumLock::createData()
{
	return data + date;
}
