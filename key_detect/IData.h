#pragma once

#include "ConsoleData.h"

class IData
{
public:
	virtual void addData(SmartConsoleData) = 0;
};