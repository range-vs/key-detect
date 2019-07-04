#include "EventData.h"

bool EventData::isAltN()
{
	return altN;
}

bool EventData::isAltO()
{
	return altO;
}

bool EventData::switchAltN()
{
	return altN = !altN;
}

bool EventData::switchAltO()
{
	return altO = !altO;
}

void EventData::setWindow(SmartHookWindow wp)
{
	windowParent = wp;
}

SmartHookWindow EventData::getWindow()
{
	return windowParent;
}

EventData::EventData(const EventData& ed)
{
	this->altN = ed.altN;
	this->altO = ed.altO;
	this->windowParent = ed.windowParent;
}

EventData& EventData::operator=(const EventData& ed)
{
	if (this != &ed)
	{
		this->altN = ed.altN;
		this->altO = ed.altO;
		this->windowParent = ed.windowParent;
	}
	return *this;
}