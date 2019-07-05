#pragma once

#include "GlobalHook.h"

class EventNumLock : public IEvent
{
	wstring data;
public:
	int run(SmartEventData gh);
	wstring createData();
};