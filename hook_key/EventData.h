#pragma once

#include "../key_detect/IHookWindow.h"

class EventData;

using SmartEventData = shsmart_pointer<EventData>;

class EventData
{
	SmartHookWindow windowParent;
	bool altN;
	bool altO;
public:
	EventData():altN(false), altO(false){}
	EventData(const EventData&);
	EventData& operator=(const EventData&);
	bool isAltN();
	bool isAltO();
	bool switchAltN();
	bool switchAltO();
	void setWindow(SmartHookWindow);
	SmartHookWindow getWindow();
};