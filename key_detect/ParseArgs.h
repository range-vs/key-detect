#pragma once

#include "types.h"

using namespace std;

class ParseArgs;

using SmartParseArgs = usmart_pointer<ParseArgs>;

class ParseArgs
{
	map<wstring, int> _args;

	void initDefault();
	vector<wstring> split(const wstring& input, wchar_t s);
public:
	ParseArgs(char* line);
	int& getValue(const wstring& key);
};