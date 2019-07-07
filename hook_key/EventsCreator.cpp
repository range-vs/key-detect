#include "EventsCreator.h"

map< KeyEvents, pair<int, int>>EventsCreator::eventsState(EventsCreator::generateEventsState());

map<KeyEvents, SmartFactoryEvent> EventsCreator::events(EventsCreator::generateEvents());

map<KeyEvents, pair<int, int>> EventsCreator::generateEventsState()
{
	return map<KeyEvents, pair<int, int>>
	{
		{KeyEvents(78, -1), { WM_SYSKEYUP, WM_SYSKEYDOWN }},
		{ KeyEvents(79, -1), {WM_SYSKEYUP, WM_SYSKEYDOWN} },
		{ KeyEvents(20, -1), {WM_KEYUP, WM_KEYDOWN} },
		{ KeyEvents(144, -1), {WM_KEYUP, WM_KEYDOWN} },
		{ KeyEvents(145, -1), {WM_KEYUP, WM_KEYDOWN} }
	};
}

map<KeyEvents, SmartFactoryEvent> EventsCreator::generateEvents()
{
	return map<KeyEvents, SmartFactoryEvent>
	{
		{KeyEvents(78, -1), SmartFactoryEvent(new FactoryEventAltN()) },
		{ KeyEvents(79, -1), SmartFactoryEvent(new FactoryEventAltO()) },
		{ KeyEvents(13, 1), SmartFactoryEvent(new FactoryEventRightEnter()) },
		{ KeyEvents(107, 0), SmartFactoryEvent(new FactoryEventRightPlus()) },
		{ KeyEvents(20, -1), SmartFactoryEvent(new FactoryEventCapsLock()) },
		{ KeyEvents(144, -1), SmartFactoryEvent(new FactoryEventNumLock()) },
		{ KeyEvents(145, -1), SmartFactoryEvent(new FactoryEventScrollLock()) }
	};
}

SmartEvent EventsCreator::create(int message, int currentCode, int flag)
{
	KeyEvents keyEvent(currentCode, flag);
	if (eventsState.find(keyEvent) == eventsState.end())
	{
		if (events.find(keyEvent) != events.end())
			return events[keyEvent]->create();
		return nullptr;
	}
	else if (eventsState[keyEvent].first != message)
	{
		eventsState[keyEvent].first = message;
		if (message == eventsState[keyEvent].second)
		{
			if (events.find(keyEvent) != events.end())
				return events[keyEvent]->create();
			return nullptr;
		}
	}
	return nullptr;
}
