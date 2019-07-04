#pragma once

#include "GlobalHook.h"

extern "C"  class Export
{
public:
	static __declspec(dllexport) IHook* CreateHook();
	static __declspec(dllexport) LRESULT WINAPI GetHookProc();
};