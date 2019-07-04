#pragma once

#include "FactoryEventAltN.h"
#include "FactoryEventAltO.h"
#include "FactoryEventCapsLock.h"
#include "FactoryEventNumLock.h"
#include "FactoryEventRightEnter.h"
#include "FactoryEventRightPlus.h"
#include "FactoryEventScrollLock.h"
#include "KeyEvents.h"

class EventsCreator
{
	EventsCreator(){}
	EventsCreator(const EventsCreator&);
	EventsCreator& operator=(const EventsCreator&);
	
	static map< KeyEvents, int> eventsState;
	static map< KeyEvents, int> generateEventsState();
	static map< KeyEvents, SmartFactoryEvent> events;
	static map< KeyEvents, SmartFactoryEvent> generateEvents();
public:
	static SmartEvent create(int message, int currentCode, int flag);
};