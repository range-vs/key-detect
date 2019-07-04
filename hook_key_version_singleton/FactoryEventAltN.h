#pragma once

#include "FactoryEvent.h"
#include "EventAltN.h"

class FactoryEventAltN : public FactoryEvent
{
public:
	SmartEvent create();
};