#pragma once

#include "stdafx.h"

class ITray
{
public:
	virtual void addNotify(const wstring& message, const wstring& title, UINT type) = 0;
};