﻿//------------------------------------------------------------------------------
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
	// Sum construction/destruction
	Sum(const Expression& left, const Expression& right);
	Sum(Expression&& left, Expression&& right);

	Sum(const Sum&) = delete;
	Sum(Sum&&) = delete;

	Sum operator=(Sum&&) = delete;
	Sum operator=(const Sum&) = delete;
	
	virtual ~Sum() = default;

	// IFunction
	Expression		RowExpression() const final;

	std::string		GetType() const override;

protected:
	// BinaryExpressionBase
	Expression		CopyImpl(Expression&& left, Expression&& right) const override;
};

}
