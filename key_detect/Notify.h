#pragma once

#include "stdafx.h"
#include "resource.h"

class Notify
{
public:
	Notify(const HWND& hwnd, const wstring& message, const wstring& title, UINT type);
};