#pragma once

#include "FactoryEvent.h"
#include "EventScrollLock.h"

class FactoryEventScrollLock : public FactoryEvent
{
public:
	SmartEvent create();
};