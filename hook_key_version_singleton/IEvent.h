#pragma once

#include "../key_detect/types.h"

class IEvent;

using SmartEvent = shsmart_pointer<IEvent>;

class IEvent
{
public:
	virtual int run() = 0;
	virtual wstring createData() = 0;
};