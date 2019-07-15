#pragma once

#include "FactoryEvent.h"
#include "EventCapsLock.h"

class FactoryEventCapsLock : public FactoryEvent
{
public:
	SmartEvent create() override;
};