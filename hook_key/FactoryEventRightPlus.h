#pragma once

#include "FactoryEvent.h"
#include "EventRightPlus.h"

class FactoryEventRightPlus : public FactoryEvent
{
public:
	SmartEvent create() override;
};