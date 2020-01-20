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

class SumProcessor : public BinaryProcessorBase
{
public:

	SumProcessor() = default;
	virtual ~SumProcessor() = default;

protected:
	Expression	SimplifyImpl(Expression&& expr) const final;
};

}
