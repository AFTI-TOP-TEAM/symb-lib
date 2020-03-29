//------------------------------------------------------------------------------
// Div.h
//
// Div implements...
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

class Div : public NthExpression<Div, 2>
{
	using Base = NthExpression<Div, 2>;
public:
	explicit Div(Expression&& left, Expression&& right);
	explicit Div(const Expression& left, const Expression& right);
	explicit Div(Arguments&& values);
	Div();

	Div(const Div&) = delete;
	Div(Div&&) = delete;

	Div operator=(Div&&) = delete;
	Div operator=(const Div&) = delete;
	
	virtual ~Div() = default;
};

}
