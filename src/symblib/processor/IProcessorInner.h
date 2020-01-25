//------------------------------------------------------------------------------
// IProcessorInner.h
//
// IProcessorInner general expression processing interface...
//
// Copyright (c) 2019 Afti
// All rights reserved.
//
// Date: 20.01.2020
// Author: Bezborodov Gleb
//------------------------------------------------------------------------------
#pragma once 

#include "../node/IExpression.h"

namespace symb
{

class IProcessorInner
{
public:
	IProcessorInner() = default;
	
	IProcessorInner(const IProcessorInner&) = delete;
	IProcessorInner(IProcessorInner&&) = delete;
	
	virtual ~IProcessorInner() = default;

	virtual Expression		Simplify(const Expression& expr) const = 0;

	virtual Expression		Derivate(const Expression& expr) const = 0;

	virtual Expression		Integrate(const Expression& expr) const = 0;

	virtual Real Compute(const Expression& expr) const = 0;
};

using Processor = std::unique_ptr<IProcessorInner>;
	
}