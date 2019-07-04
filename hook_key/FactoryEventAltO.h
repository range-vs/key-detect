#pragma once

#include "FactoryEvent.h"
#include "EventAltO.h"

class FactoryEventAltO : public FactoryEvent
{
public:
	SmartEvent create();
};