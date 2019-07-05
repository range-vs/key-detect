#pragma once

#include "GlobalHook.h"

class EventCapsLock : public IEvent
{
	wstring data;
public:
	int run();
	wstring createData();
};