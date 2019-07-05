#pragma once

#include "FactoryEvent.h"
#include "EventNumLock.h"

class FactoryEventNumLock : public FactoryEvent
{
public:
	SmartEvent create();
};