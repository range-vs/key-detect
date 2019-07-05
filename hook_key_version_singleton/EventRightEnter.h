#pragma once

#include "GlobalHook.h"

class EventRightEvent : public IEvent
{
	bool isData;
public:
	int run();
	wstring createData();
};