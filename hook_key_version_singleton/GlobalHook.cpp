#include "GlobalHook.h"

GlobalHook* GlobalHook::instance(nullptr);

void GlobalHook::setWindow(SmartHookWindow wp)
{
	windowParent = wp;
}

SmartHookWindow GlobalHook::getWindow()
{
	return windowParent;
}

LRESULT WINAPI GlobalHook::HookProc(int code, WPARAM wParam, LPARAM lParam)
{
	return GlobalHook::getInstance()->MsgProc(code, wParam, lParam);
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
			result = event->run();
			events.push_back(event);
		}
		if (result == 1)
			return result;
	}

	OutputDebugString(to_wstring(key).c_str());
	OutputDebugString(L"\n");

	return CallNextHookEx(hCBTHook, code, wParam, lParam);
}

void GlobalHook::init()
{
	altN = false;
	altO = false;
}

GlobalHook* GlobalHook::getInstance()
{
	if (!instance)
		instance = new GlobalHook();
	return instance;
}

void GlobalHook::clear()
{
	if (instance)
		delete instance;
	instance = nullptr;
	OutputDebugString(L"Clear Global hook\n");
}

bool GlobalHook::isAltN()
{
	return altN;
}

bool GlobalHook::isAltO()
{
	return altO;
}

bool GlobalHook::switchAltN()
{
	return altN = !altN;
}

bool GlobalHook::switchAltO()
{
	return altO = !altO;
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

