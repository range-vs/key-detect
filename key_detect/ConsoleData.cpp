#include "ConsoleData.h"

ConsoleData::ConsoleData(const ConsoleData& cd)
{
	this->data = cd.data;
}

ConsoleData& ConsoleData::operator=(const ConsoleData& cd)
{
	if(this != &cd)
		this->data = cd.data;
	return *this;
}

vector<wstring>::iterator ConsoleData::getStartNewData()
{
	return data.begin() + (data.size() - newDataCounter);
}

int ConsoleData::getNewCountData()const
{
	return newDataCounter;
}

void ConsoleData::clearNewCountData()
{
	newDataCounter = 0;
}

void ConsoleData::addData(wstring l)
{
	data.push_back(l);
	newDataCounter++;
}