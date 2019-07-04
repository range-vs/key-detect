#include "KeyEvents.h"

KeyEvents::KeyEvents(int cc, int f): currentCode(cc), flag(f) { }

KeyEvents::KeyEvents(const KeyEvents& ke)
{
	currentCode = ke.currentCode;
	flag = ke.flag;
}

KeyEvents& KeyEvents::operator=(const KeyEvents& ke)
{
	if (this != &ke)
	{
		currentCode = ke.currentCode;
		flag = ke.flag;
	}
	return *this;
}

bool KeyEvents::operator<(const KeyEvents& ke) const
{
	/*if (this->prewCode == ke.prewCode) 
	{
		if (this->currentCode == ke.currentCode) 
		{
			if (this->flag >= ke.flag)
				return false;
			else
				return true;
		}
		else if (this->currentCode > ke.currentCode)
			return false;
		else
			return true;
	}
	else if (this->prewCode > ke.prewCode)
		return false;
	else
		return true;*/
	if (this->currentCode > ke.currentCode)
		return true;
	else if (this->currentCode < ke.currentCode)
		return false;
	else
	{
		if (this->flag > ke.flag)
			return true;
		else if (this->flag < ke.flag)
			return false;
		return false;
	}
}
