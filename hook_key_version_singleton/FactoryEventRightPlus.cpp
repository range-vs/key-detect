#include "FactoryEventRightPlus.h"

SmartEvent FactoryEventRightPlus::create()
{
	return SmartEvent(new EventRightPlus());
}
