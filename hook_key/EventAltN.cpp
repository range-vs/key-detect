#include "EventAltN.h"

int EventAltN::run(SmartEventData gh)
{
	if (GetKeyState(160) & 0x80 || GetKeyState(161) & 0x80)
	{
		data = L"������ ���������� alt + N\n";
		data += gh->isAltN() ? L"\n������ enter ����� ������������� ������ ��������\n" : L"\n������ enter ������� ��� �������� �� '�'\n";
		gh->switchAltN();
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

wstring EventAltN::createData()
{
	return data;
}
