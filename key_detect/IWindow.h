#pragma once

#include "stdafx.h"

class IWindow
{
public:
	virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM) = 0;
	virtual HWND& getDescriptor() = 0;
};