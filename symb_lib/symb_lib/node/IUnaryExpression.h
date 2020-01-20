//------------------------------------------------------------------------------
// IUnaryExpression.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------
#pragma once

#include "IExpression.h"

namespace symb
{

class IUnaryExpression : public IExpression
{
public:

	IUnaryExpression() = default;
	virtual ~IUnaryExpression() = default;

	virtual void				SetArg(Expression&& arg) = 0;
	virtual void				SetArg(const Expression& arg) = 0;
	virtual const Expression&	GetArg() const = 0;
};

}