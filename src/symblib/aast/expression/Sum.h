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

class Sum : public NthExpression<Sum>
{

public:
	explicit Sum(const Expression& left, const Expression& right);
	explicit Sum(std::vector<Expression>&& values);
	explicit Sum(Expression&& left, Expression&& right);

	Sum();
	
	Sum(const Sum&) = delete;
	Sum(Sum&&) = delete;

	Sum operator=(Sum&&) = delete;
	Sum operator=(const Sum&) = delete;
	
	virtual ~Sum() = default;
};

}
