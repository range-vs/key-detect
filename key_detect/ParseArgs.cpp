#include "ParseArgs.h"

void ParseArgs::initDefault()
{
	_args.insert({ L"ms", 5 });
}

std::vector<std::wstring> ParseArgs::split(const std::wstring& input, wchar_t s)
{
	std::wstringstream test(input);
	std::wstring segment;
	std::vector<std::wstring> seglist;

	while (std::getline(test, segment, s))
		if(segment.size() != 0)
			seglist.push_back(segment);
	return seglist;
}

ParseArgs::ParseArgs(char* line)
{
	this->initDefault();
	vector<wstring> keys(this->split(wstring(line, line + strlen(line)), L'-'));
	for (auto&& k : keys)
	{
		vector<wstring> value(this->split(k, L' '));
		if (value.size() != 2)
			throw wstring(L"Error input args cmd!");
		int v(-1);
		std::wistringstream ss(value[1]);
		ss >> v;
		if(!ss)
			throw wstring(L"Error value for arg cmd: " + value[0]);
		if (_args.find(value[0]) == _args.end())
			_args.insert({ value[0], v });
		else
			_args[value[0]] = v;
	}
}

int& ParseArgs::getValue(const wstring& key)
{
	if (_args.find(key) == _args.end())
		throw wstring(L"Error find arg cmd: key - " + key);
	return _args[key];
}