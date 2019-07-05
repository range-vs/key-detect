#pragma once

#include "stdafx.h"
#include "Deleter.h"

template <class T> using usmart_pointer =  unique_ptr<T,  Deleter>;
template <class T> using shsmart_pointer =  shared_ptr<T>;
