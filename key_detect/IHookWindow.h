#pragma once

#include "IWindow.h"
#include "ITray.h"
#include "IInitialize.h"
#include "IConteinerControl.h"
#include "IData.h"
#include "IInitControl.h"
#include "IMenu.h"

class IHookWindow;

using SmartHookWindow = shsmart_pointer<IHookWindow>;

class IHookWindow : public IWindow, public ITray, public IInitControl, public IConteinerControl, public IMenu
{

};
