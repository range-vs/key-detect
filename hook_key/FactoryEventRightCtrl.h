#pragma once

#include "FactoryEvent.h"
#include "EventRightCtrl.h"

class FactoryEventRightCtrl : public FactoryEvent
{
public:
	SmartEvent create() override;
};