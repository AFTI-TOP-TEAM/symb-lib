//------------------------------------------------------------------------------
// BinaryProcessorBase.h
//
// BinaryProcessorBase implements...
//
// Copyright (c) 2019 GlenSand
// All rights reserved.
//
// Date: 20.01.2020
// Author: Bezborodov Gleb
//------------------------------------------------------------------------------
#pragma once

#include "IProcessorInner.h"

namespace symb
{

class BinaryProcessorBase : IProcessorInner
{
public:
	BinaryProcessorBase() = default;
	virtual ~BinaryProcessorBase() = default;

	Expression			Simplify(const Expression& expr) const final;

protected:
	virtual Expression	SimplifyImpl(Expression&& expr) const = 0;
};

}

