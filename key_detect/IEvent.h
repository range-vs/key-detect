#pragma once

#include "ConsoleData.h"

class IEvent
{
	virtual void run() = 0;
	virtual SmartConsoleData generateData() = 0;
};