#include "FactoryEventNumLock.h"

SmartEvent FactoryEventNumLock::create()
{
	return SmartEvent(new EventNumLock());
}
