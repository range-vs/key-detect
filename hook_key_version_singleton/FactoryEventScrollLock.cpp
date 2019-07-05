#include "FactoryEventScrollLock.h"

SmartEvent FactoryEventScrollLock::create()
{
	return SmartEvent(new EventScrollLock());
}
