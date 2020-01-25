//------------------------------------------------------------------------------
// Const.h
//
// Const implements...
//
// Copyright (c) 2019 GlenSand
// All rights reserved.
//
// Date: 1.01.2020
// Author: glensand
//------------------------------------------------------------------------------
#pragma once

#include "Var.h"

namespace symb
{

class Const : public Var
{
public:
	Const(Real val = 0.0, const std::string& label = "");
	virtual ~Const() = default;

};

}

