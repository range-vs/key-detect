#include "EventAltO.h"

int EventAltO::run()
{
	if (GetKeyState(160) & 0x80 || GetKeyState(161) & 0x80)
	{
		data = L"������ ���������� alt + O\n";
		data += GlobalHook::getInstance()->isAltO() ? L"\n������ \"+\" ����� ������������� ������ ��������\n" : L"\n������ \"+\" ������� ��� �������� �� \"���\"\n";
		GlobalHook::getInstance()->switchAltO();
		time_t seconds = time(NULL);
		tm timeinfo;
		localtime_s(&timeinfo, &seconds);
		char buf[500];
		asctime_s(buf, 500, &timeinfo);
		//data += buf;
		GlobalHook::getInstance()->getWindow()->addNotify(data, L"�����������", NIM_MODIFY);
	}
	return 0;
}

wstring EventAltO::createData()
{
	return data;
}
