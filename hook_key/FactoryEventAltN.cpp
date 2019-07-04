#include "FactoryEventAltN.h"

SmartEvent FactoryEventAltN::create()
{
	return SmartEvent(new EventAltN());
}
