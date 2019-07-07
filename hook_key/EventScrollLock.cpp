#include "EventScrollLock.h"

int EventScrollLock::run(SmartEventData gh)
{
	data = L"Нажата клавиша Scroll Lock\n";
	if ((GetKeyState(VK_SCROLL) && 1) == 0)
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

wstring EventScrollLock::createData()
{
	return data + date;
}
