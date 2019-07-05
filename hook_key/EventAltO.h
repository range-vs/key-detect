#pragma once

#include "GlobalHook.h"

class EventAltO : public IEvent
{
	wstring data;
public:
	int run(SmartEventData gh);
	wstring createData();
};