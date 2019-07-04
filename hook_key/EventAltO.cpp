#include "EventAltO.h"

int EventAltO::run(SmartEventData gh)
{
	if (GetKeyState(160) & 0x80 || GetKeyState(161) & 0x80)
	{
		data = L"������ ���������� alt + O\n";
		data += gh->isAltO() ? L"\n������ \"+\" ����� ������������� ������ ��������\n" : L"\n������ \"+\" ������� ��� �������� �� \"���\"\n";
		gh->switchAltO();
		time_t seconds = time(NULL);
		tm timeinfo;
		localtime_s(&timeinfo, &seconds);
		char buf[500];
		asctime_s(buf, 500, &timeinfo);
		//data += buf;
		gh->getWindow()->addNotify(data, L"�����������", NIM_MODIFY);
	}
	return 0;
}

wstring EventAltO::createData()
{
	return data;
}
