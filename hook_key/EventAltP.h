#pragma once

#include "GlobalHook.h"

class EventAltP : public IEvent
{
	wstring data;
	wstring date;
public:
	int run(SmartEventData gh) override;
	wstring createData() override;
};