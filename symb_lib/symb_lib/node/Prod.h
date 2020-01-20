//------------------------------------------------------------------------------
// Prod.h
//
// Prod implements...
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 20.01.2020
// Author: Bezborodov Gleb
//------------------------------------------------------------------------------
#pragma once

#include "BinaryExpressionBase.h"

namespace symb
{

class Prod : public BinaryExpressionBase
{
public:
	Prod(Expression&& left, Expression&& right);
	Prod(const Expression& left, const Expression& right);
	
	virtual ~Prod() = default;
	
protected:
	Real		ComputeImpl(Real left, Real right) const override;

	Expression	ExecuteImpl() override;

	Expression	DerivateImpl(Expression&& left, Expression&& right) const override;

	Expression	CopyImpl(Expression&& left, Expression&& right) const override;
};

}
