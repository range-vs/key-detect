#pragma once

#include "GlobalHook.h"

class EventRightPlus : public IEvent
{
	bool isData;
public:
	int run();
	wstring createData();
};