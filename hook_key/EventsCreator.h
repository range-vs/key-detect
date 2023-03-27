#pragma once

#include "FactoryEventAltN.h"
#include "FactoryEventAltO.h"
#include "FactoryEventAltP.h"
#include "FactoryEventCapsLock.h"
#include "FactoryEventNumLock.h"
#include "FactoryEventRightEnter.h"
#include "FactoryEventRightPlus.h"
#include "FactoryEventRightCtrl.h"
#include "FactoryEventScrollLock.h"
#include "KeyEvents.h"

class EventsCreator
{
	EventsCreator(){}
	EventsCreator(const EventsCreator&);
	EventsCreator& operator=(const EventsCreator&);
	
	static map< KeyEvents, pair<int, int>> eventsState;
	static map< KeyEvents, pair<int, int>> generateEventsState();
	static map< KeyEvents, SmartFactoryEvent> events;
	static map< KeyEvents, SmartFactoryEvent> generateEvents();
public:
	static SmartEvent create(int message, int currentCode, int flag);
};