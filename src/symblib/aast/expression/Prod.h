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

#include "NthExpression.h"

namespace symb
{

class Prod : public NthExpression<Prod, 2>
{
	using Base = NthExpression<Prod, 2>;
public:

	explicit Prod(Expression&& left, Expression&& right);
	explicit Prod(const Expression& left, const Expression& right);
	explicit Prod(Arguments&& values);
	
	Prod();

	Prod(const Prod&) = delete;
	Prod(Prod&&) = delete;

	Prod operator=(Prod&&) = delete;
	Prod operator=(const Prod&) = delete;
	
	virtual ~Prod() = default;
};

}
