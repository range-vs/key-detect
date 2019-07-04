#include "FactoryEventRightEnter.h"

SmartEvent FactoryEventRightEnter::create()
{
	return SmartEvent(new EventRightEvent());
}
