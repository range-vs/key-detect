#pragma once

#include "types.h"

class IInitControl;

class IInitControl
{
public:
	virtual void init(HWND, HINSTANCE) = 0;
};