﻿//------------------------------------------------------------------------------
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

#include "BinaryExpressionBase.h"

namespace symb
{

class Div : public BinaryExpressionBase
{
public:

	Div(Expression&& left, Expression&& right);
	Div(const Expression& left, const Expression& right);
	
	virtual ~Div() = default;

	// IFunction
	Expression		RowExpression() const final;

	std::string		GetType() const override;

protected:
	// BinaryExpressionBase
	Expression		CopyImpl(Expression&& left, Expression&& right) const override;
};

}