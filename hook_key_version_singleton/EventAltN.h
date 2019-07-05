#pragma once

#include "GlobalHook.h"

class EventAltN : public IEvent
{
	wstring data;
public:
	int run();
	wstring createData();
};