#pragma once

#include "../key_detect/IHookWindow.h"
#include "IEvent.h"

class IHook
{
public:
	virtual void setWindow(SmartHookWindow) = 0;
	virtual SmartHookWindow getWindow() = 0;
	virtual LRESULT MsgProc(int, WPARAM, LPARAM) = 0;
	virtual void clear() = 0;
	virtual void addEvent(SmartEvent) = 0;
	virtual vector<SmartEvent>& getEvents() = 0;
	virtual void setHHook(HHOOK) = 0;
	virtual ~IHook() = 0 {};
};