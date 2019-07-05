#include "GlobalHook.h"

void GlobalHook::createEventData(SmartHookWindow wp)
{
	eventData->setWindow(wp);
}

LRESULT GlobalHook::MsgProc(int code, WPARAM wParam, LPARAM lParam)
{
	KBDLLHOOKSTRUCT hooked_key; // получаем код клавиши 
	hooked_key = *((KBDLLHOOKSTRUCT*)lParam);
	int key = hooked_key.vkCode; 

	if (wParam == WM_KEYDOWN || wParam == WM_KEYUP)
	{
		int flag(-1);
		if (key == 107 || key == 13)
			flag = hooked_key.flags;
		int currentCode(key);
		SmartEvent event = EventsCreator::create(wParam, currentCode, flag);
		int result(-1);
		if (event)
		{
			result = event->run(eventData);
			events.push_back(event);
		}
		if (result == 1)
			return result;
	}

#ifndef NDEBUG
	OutputDebugString(to_wstring(key).c_str());
	OutputDebugString(L"\n");
#endif

	return CallNextHookEx(hCBTHook, code, wParam, lParam);
}

void GlobalHook::init()
{
	eventData.reset(new EventData());
}

void GlobalHook::addEvent(SmartEvent se)
{
	events.push_back(se);
}

vector<SmartEvent>& GlobalHook::getEvents()
{
	return events;
}

void GlobalHook::setHHook(HHOOK hhook)
{
	hCBTHook = hhook;
}

GlobalHook::~GlobalHook()
{
	OutputDebugString(L"Delete Global hook\n");
}

