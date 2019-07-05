#include "FactoryEventAltO.h"

SmartEvent FactoryEventAltO::create()
{
	return SmartEvent(new EventAltO());
}
