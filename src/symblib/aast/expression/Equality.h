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

#include "NthExpression.h"

namespace symb
{

class Equality final : public NthExpression<Equality, 1>
{
	using Base = NthExpression<Equality, 1>;
public:
	Equality();
	explicit Equality(Expression&& left, Expression&& right);
	explicit Equality(const Expression& left, const Expression& right);
	explicit Equality(Arguments&& values);
	
	Equality(const Equality&) = delete;
	Equality(Equality&&) = delete;

	Equality operator=(Equality&&) = delete;
	Equality operator=(const Equality&) = delete;
	
	virtual ~Equality() = default;
};

}
