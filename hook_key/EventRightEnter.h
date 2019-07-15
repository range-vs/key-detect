#pragma once

#include "GlobalHook.h"

class EventRightEvent : public IEvent
{
	bool isData;
	wstring date;
public:
	int run(SmartEventData gh) override;
	wstring createData() override;
};