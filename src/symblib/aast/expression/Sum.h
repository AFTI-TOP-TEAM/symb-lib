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

#include "NthExpression.h"

namespace symb
{

class Sum : public NthExpression<Sum, 2>
{
	using Base = NthExpression<Sum, 2>;
public:
	explicit Sum(const Expression& left, const Expression& right);
	explicit Sum(Arguments&& values);
	explicit Sum(Expression&& left, Expression&& right);

	Sum();
	
	Sum(const Sum&) = delete;
	Sum(Sum&&) = delete;

	Sum operator=(Sum&&) = delete;
	Sum operator=(const Sum&) = delete;
	
	virtual ~Sum() = default;
};

}
