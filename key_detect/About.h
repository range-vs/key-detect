#pragma once

#include "stdafx.h"

class About
{
	wstring title;
	wstring message;
	HWND hwnd;
public:
	About(const HWND& hwnd, const wstring& title, const wstring& message);
	void show();
};