#pragma once

#include "GlobalHook.h"

class EventRightPlus : public IEvent
{
	bool isData;
	wstring date;
public:
	int run(SmartEventData gh);
	wstring createData();
};