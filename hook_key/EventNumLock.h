﻿#pragma once

#include "GlobalHook.h"

class EventNumLock : public IEvent
{
	wstring data;
	wstring date;
public:
	int run(SmartEventData gh) override;
	wstring createData() override;
};