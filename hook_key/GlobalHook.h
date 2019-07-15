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
	void createEventData(SmartHookWindow) override;
	LRESULT MsgProc(int, WPARAM, LPARAM) override;
	void init() override;

	void addEvent(SmartEvent) override;
	vector<SmartEvent>& getEvents() override;
	void setHHook(HHOOK) override;
	~GlobalHook();
};
