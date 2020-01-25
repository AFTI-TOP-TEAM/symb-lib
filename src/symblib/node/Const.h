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

class Const final : public Var
{
public:
	explicit Const(Real val = 0.0, const std::string& label = "");
	
	Const(const Const&) = delete;
	Const(Const&&) = delete;

	Const operator=(Const&&) = delete;
	Const operator=(const Const&) = delete;

	virtual ~Const() = default;
	
	std::string GetType() const override;
};

}

