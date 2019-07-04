#include "EventNumLock.h"

int EventNumLock::run(SmartEventData gh)
{
	data = L"������ ������� Num Lock\n";
	if ((GetKeyState(VK_NUMLOCK) && 1) == 0)
		data += L"������� ������������\n";
	else
		data += L"������� ��������������\n";
	gh->getWindow()->addNotify(data, L"�����������", NIM_MODIFY);
	return 0;
}

wstring EventNumLock::createData()
{
	return data;
}
