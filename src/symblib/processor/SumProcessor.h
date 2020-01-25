//------------------------------------------------------------------------------
// SumProcessor.h
//
// SumProcessor implements...
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 21.01.2020
// Author: Bezborodov Gleb
//------------------------------------------------------------------------------
#pragma once

#include "BinaryProcessorBase.h"

namespace symb
{

class SumProcessor final : public BinaryProcessorBase
{
public:

	SumProcessor() = default;

	SumProcessor(const SumProcessor&) = delete;
	SumProcessor(SumProcessor&&) = delete;

	SumProcessor operator=(const SumProcessor&) = delete;
	SumProcessor operator=(SumProcessor&&) = delete;
	
	virtual ~SumProcessor() = default;

protected:

	Real ComputeImpl(Expression&& expr) const override;

	Expression		IntegrateImpl(Expression&& expr) const override;

	Expression		DerivateImpl(Expression&& expr) const override;

	Expression		SimplifyImpl(Expression&& expr) const override;
};

}
