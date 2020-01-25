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

	Prod(const Prod&) = delete;
	Prod(Prod&&) = delete;

	Prod operator=(Prod&&) = delete;
	Prod operator=(const Prod&) = delete;
	
	virtual ~Prod() = default;

	// IFunction
	Expression		RowExpression() const final;

	std::string		GetType() const override;
protected:
	// BinaryExpressionBase
	Expression		CopyImpl(Expression&& left, Expression&& right) const override;
};

}
