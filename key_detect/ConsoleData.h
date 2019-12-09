#pragma once

#include "types.h"

class ConsoleData;

using SmartConsoleData = shsmart_pointer<ConsoleData>;

class ConsoleData
{
	int newDataCounter;
	vector<wstring> data;
public:
	ConsoleData():newDataCounter(0){}
	ConsoleData(const ConsoleData& cd);
	ConsoleData& operator=(const ConsoleData& cd);
	vector<wstring>& getData() { return data; }
	vector<wstring>::iterator getStartNewData();
	int getNewCountData()const;
	void clearNewCountData();
	void addData(const wstring& l);
};