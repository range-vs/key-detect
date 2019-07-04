#pragma once

#include "GlobalHook.h"

class EventAltO : public IEvent
{
	wstring data;
public:
	int run();
	wstring createData();
};