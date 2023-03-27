#pragma once

#include "../key_detect/IHookWindow.h"

class EventData;

using SmartEventData = shsmart_pointer<EventData>;

class EventData
{
	SmartHookWindow windowParent;
	bool altN;
	bool altO;
	bool altP;

public:
	EventData():altN(false), altO(false), altP(false){}
	EventData(const EventData&);
	EventData& operator=(const EventData&);
	bool isAltN();
	bool isAltO();
	bool isAltP();
	bool switchAltN();
	bool switchAltO();
	bool switchAltP();
	void setWindow(SmartHookWindow);
	SmartHookWindow getWindow();
};