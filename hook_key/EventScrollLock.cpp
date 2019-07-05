﻿#include "EventScrollLock.h"

int EventScrollLock::run(SmartEventData gh)
{
	data = L"Нажата клавиша Scroll Lock\n";
	if ((GetKeyState(VK_SCROLL) && 1) == 0)
		data += L"Клавиша активирована\n";
	else
		data += L"Клавиша деактивирована\n";
	gh->getWindow()->addNotify(data, L"Уведомление", NIM_MODIFY);
	return 0;
}

wstring EventScrollLock::createData()
{
	return data;
}
