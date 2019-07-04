#pragma once

#include "IEvent.h"

class FactoryEvent;

using SmartFactoryEvent = shsmart_pointer< FactoryEvent>;

class FactoryEvent
{
public:
	virtual SmartEvent create() = 0;
};