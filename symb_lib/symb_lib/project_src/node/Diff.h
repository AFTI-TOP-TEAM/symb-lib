//------------------------------------------------------------------------------
// Diff.h
//
// Diff implements...
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 1.20.2020
// Author: Bezborodov Gleb
//------------------------------------------------------------------------------
#pragma once

#include "BinaryExpressionBase.h"

namespace symb
{

class Diff : public BinaryExpressionBase
{
public:

	Diff(Expression&& left, Expression&& right);
	Diff(const Expression& left, const Expression& right);
	
	virtual ~Diff() = default;

	// IFunction
	Expression	RowExpression() const final;

protected:
	// BinaryExpressionBase
	Real		ComputeImpl(Real left, Real right) const override;

	Expression	ExecuteImpl() override;

	Expression	DerivateImpl(Expression&& left, Expression&& right) const override;

	Expression	CopyImpl(Expression&& left, Expression&& right) const override;
};

}
