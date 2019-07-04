#include "export.h"

IHook* Export::CreateHook()
{
	return new GlobalHook();
}