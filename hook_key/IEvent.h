#pragma once

#include "EventData.h"

class IEvent;

using SmartEvent = shsmart_pointer<IEvent>;

class IEvent
{
public:
	virtual int run(SmartEventData gh) = 0;
	virtual wstring createData() = 0;
};