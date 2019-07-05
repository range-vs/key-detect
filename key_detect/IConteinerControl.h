#pragma once

#include "IControl.h"
#include "ConsoleData.h"

class IConteinerControl
{
public:
	virtual void addControl(SmartControl) = 0;
	virtual void mailingEvents(SmartConsoleData) = 0;
};