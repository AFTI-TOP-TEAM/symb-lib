//------------------------------------------------------------------------------
// BinaryProcessorBase.h
//
// BinaryProcessorBase implements...
//
// Copyright (c) 2020 Afti
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

	Expression			Derivate(const Expression& expr) const final;

	Expression			Integrate(const Expression& expr) const final;

	Real				Compute(const Expression& expr) const final;

protected:
	virtual Expression	SimplifyImpl(Expression&& expr) const = 0;

	virtual Real ComputeImpl(Expression&& expr) const = 0;
	
	virtual Expression	IntegrateImpl(Expression&& expr) const = 0;

	virtual Expression	DerivateImpl(Expression&& expr) const = 0;
};

}

