#include "FactoryEventRightCtrl.h"

SmartEvent FactoryEventRightCtrl::create()
{
	return SmartEvent(new EventRightCtrl());
}
