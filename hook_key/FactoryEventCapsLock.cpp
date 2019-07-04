#include "FactoryEventCapsLock.h"

SmartEvent FactoryEventCapsLock::create()
{
	return SmartEvent(new EventCapsLock());
}
