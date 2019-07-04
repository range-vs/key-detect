#include "EventCapsLock.h"

int EventCapsLock::run()
{
	data = L"Нажата клавиша Caps Lock\n";
	if ((GetKeyState(VK_CAPITAL) && 1) == 0) 
		data += L"Клавиша активирована\n";
	else
		data += L"Клавиша деактивирована\n";
	GlobalHook::getInstance()->getWindow()->addNotify(data, L"Уведомление", NIM_MODIFY);
	return 0;
}

wstring EventCapsLock::createData()
{
	return data;
}
