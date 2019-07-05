#include "LoaderDll.h"

LoaderDll::LoaderDll(const wchar_t* path): path(path)
{
	try
	{
		hInstDll = LoadLibrary(path);
		if (!hInstDll)
			throw wstring(L"error load DLL! Path: " + wstring(path));
	}
	catch (wstring& err)
	{
		this->clear();
		throw err;
	}
}

void* LoaderDll::getExportMember(const wchar_t* name)
{
	wstring convert(name);
	wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;
	string path(converter.to_bytes(convert));
	return GetProcAddress(hInstDll, path.c_str());
}

HINSTANCE& LoaderDll::getHinstance()
{
	return hInstDll;
}

LoaderDll::~LoaderDll()
{
	this->clear();
}

void LoaderDll::clear()
{
	if (hInstDll)
		FreeLibrary(hInstDll);
	hInstDll = nullptr;
}