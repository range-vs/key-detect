#pragma once

#include "types.h"

class LoaderDll;

using  SmartLoaderDll = usmart_pointer<LoaderDll>;

class LoaderDll
{
	HINSTANCE hInstDll;
	wstring path;
public:
	LoaderDll(const wchar_t* path);
	void* getExportMember(const wchar_t* name);
	HINSTANCE& getHinstance();
	~LoaderDll();
private:
	void clear();
};