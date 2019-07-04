#pragma once

#include "IHook.h"
#include "EventsCreator.h"
#include "EventData.h"

class GlobalHook;

class GlobalHook: public IHook, public IInitialize
{
	vector< SmartEvent> events;
	HHOOK hCBTHook;
	SmartEventData eventData;

public:
	void createEventData(SmartHookWindow);
	LRESULT MsgProc(int, WPARAM, LPARAM);
	void init();

	void addEvent(SmartEvent);
	vector<SmartEvent>& getEvents();
	void setHHook(HHOOK);
	~GlobalHook();
};
