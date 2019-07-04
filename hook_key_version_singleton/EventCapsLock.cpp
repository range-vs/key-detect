#include "EventCapsLock.h"

int EventCapsLock::run()
{
	data = L"������ ������� Caps Lock\n";
	if ((GetKeyState(VK_CAPITAL) && 1) == 0) 
		data += L"������� ������������\n";
	else
		data += L"������� ��������������\n";
	GlobalHook::getInstance()->getWindow()->addNotify(data, L"�����������", NIM_MODIFY);
	return 0;
}

wstring EventCapsLock::createData()
{
	return data;
}
