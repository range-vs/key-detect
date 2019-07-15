#pragma once

#include "GlobalHook.h"

 class Export
{
public:
	static __declspec(dllexport) IHook* CreateHook();
};