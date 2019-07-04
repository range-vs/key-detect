#pragma once

#include "IHook.h"
#include "EventsCreator.h"

class GlobalHook: public IHook, public IInitialize // singleton
{
	SmartHookWindow windowParent;
	bool altN;
	bool altO;
	vector< SmartEvent> events;
	HHOOK hCBTHook;

	GlobalHook(){}
	GlobalHook(const GlobalHook&);
	GlobalHook& operator=(const GlobalHook&);
	static GlobalHook* instance;
public:
	static LRESULT WINAPI HookProc(int, WPARAM, LPARAM);
	static GlobalHook* getInstance();

	void setWindow(SmartHookWindow);
	SmartHookWindow getWindow();
	LRESULT MsgProc(int, WPARAM, LPARAM);
	void init();
	void clear();
	bool isAltN();
	bool isAltO();
	bool switchAltN();
	bool switchAltO();
	void addEvent(SmartEvent);
	vector<SmartEvent>& getEvents();
	void setHHook(HHOOK);
	~GlobalHook();
};
