#pragma once

#include "stdafx.h"

class IWindow
{
public:
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM) = 0;
	virtual HWND& getDescriptor() = 0;
};