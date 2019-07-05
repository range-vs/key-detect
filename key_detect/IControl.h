#pragma once

#include "IWindow.h"
#include "IData.h"
#include "IInitControl.h"

class IControl;

using SmartControl= shsmart_pointer<IControl>;

class IControl : public IWindow, public IInitControl, public IData
{

};
