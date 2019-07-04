#pragma once

#include "stdafx.h"

class IMenu
{
public:
	virtual void addMenuAction(int, function<void()>) = 0;
};