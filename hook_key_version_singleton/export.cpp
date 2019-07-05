#include "export.h"

IHook* Export::CreateHook()
{
	return GlobalHook::getInstance();
}

LRESULT __stdcall Export::GetHookProc()
{
	return (LRESULT)GlobalHook::HookProc;
}