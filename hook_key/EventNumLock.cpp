#include "EventNumLock.h"

int EventNumLock::run(SmartEventData gh)
{
	data = L"Нажата клавиша Num Lock\n";
	if ((GetKeyState(VK_NUMLOCK) && 1) == 0)
		data += L"Клавиша активирована\n";
	else
		data += L"Клавиша деактивирована\n";
	gh->getWindow()->addNotify(data, L"Уведомление", NIM_MODIFY);
	return 0;
}

wstring EventNumLock::createData()
{
	return data;
}
