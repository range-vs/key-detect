#include "FactoryEventAltO.h"

SmartEvent FactoryEventAltP::create()
{
	return SmartEvent(new EventAltP());
}
