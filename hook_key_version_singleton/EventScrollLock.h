#pragma once

#include "GlobalHook.h"

class EventScrollLock : public IEvent
{
	wstring data;
public:
	int run();
	wstring createData();
};