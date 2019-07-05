#pragma once

class KeyEvents
{
	int currentCode;
	int flag;
public:
	KeyEvents(int cc, int f);
	KeyEvents(const KeyEvents& ke);
	KeyEvents& operator=(const KeyEvents& ke);
	bool operator<(const KeyEvents& ke)const;

};