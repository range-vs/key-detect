#pragma once

#include "FactoryEvent.h"
#include "EventAltP.h"

class FactoryEventAltP : public FactoryEvent
{
public:
	SmartEvent create() override;
};