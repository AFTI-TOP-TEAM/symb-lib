//------------------------------------------------------------------------------
// Summ.h
//
// Summ implements...
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

class Sum : public BinaryExpressionBase
{

public:
	Sum(const Expression& left, const Expression& right);
	Sum(Expression&& left, Expression&& right);
	
	virtual ~Sum() = default;

	// IFunction
	Expression	RowExpression() const final;
	
protected:
	// BinaryExpressionBase
	Expression	ExecuteImpl() override;

	Real		ComputeImpl(Real left, Real right) const override;

	Expression	DerivateImpl(Expression&& left, Expression&& right) const override;

	Expression	CopyImpl(Expression&& left, Expression&& right) const override;
};

}
