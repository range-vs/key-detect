#pragma once

#include "FactoryEvent.h"
#include "EventRightEnter.h"

class FactoryEventRightEnter : public FactoryEvent
{
public:
	SmartEvent create() override;
};