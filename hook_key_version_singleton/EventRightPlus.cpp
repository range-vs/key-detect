#include "EventRightPlus.h"

int EventRightPlus::run()
{
	if (GlobalHook::getInstance()->isAltO())
	{
		std::array<WORD, 3> _key = { 0x4A, 0x43, 0x44 }; // �, �, �
		for (const WORD& k : _key)
		{
			INPUT ip;
			ip.type = INPUT_KEYBOARD;
			ip.ki.time = 0;
			ip.ki.wVk = k;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT)); // ���������� ������� ������� � ���� ������� ���������
		}
		return 1;
	}
	return 0;
}

wstring EventRightPlus::createData()
{
	if (isData)
		return L"����� '+'(���)\n";
	return L"";
}
