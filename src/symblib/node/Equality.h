//------------------------------------------------------------------------------
// Equality.h
//
// Equality implements...
//
// Copyright (c) 2019 GlenSand
// All rights reserved.
//
// Date: 25.01.2020
// Author: glensand
//------------------------------------------------------------------------------
#pragma once

#include "BinaryExpressionBase.h"

namespace symb
{

class Equality final : public BinaryExpressionBase
{
public:
	Equality() = default;
	Equality(Expression&& left, Expression&& right);
	Equality(const Expression& left, const Expression& right);

	Equality(const Equality&) = delete;
	Equality(Equality&&) = delete;

	Equality operator=(Equality&&) = delete;
	Equality operator=(const Equality&) = delete;
	
	virtual ~Equality() = default;

	Expression		RowExpression() const override;

	std::string		GetType() const override;

protected:
	Expression		CopyImpl(Expression&& left, Expression&& right) const override;
};

}
