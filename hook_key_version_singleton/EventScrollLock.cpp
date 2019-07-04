#include "EventScrollLock.h"

int EventScrollLock::run()
{
	data = L"������ ������� Scroll Lock\n";
	if ((GetKeyState(VK_SCROLL) && 1) == 0)
		data += L"������� ������������\n";
	else
		data += L"������� ��������������\n";
	GlobalHook::getInstance()->getWindow()->addNotify(data, L"�����������", NIM_MODIFY);
	return 0;
}

wstring EventScrollLock::createData()
{
	return data;
}
