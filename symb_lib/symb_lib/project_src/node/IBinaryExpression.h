//------------------------------------------------------------------------------
// IBinaryExpression.h
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

class IBinaryExpression : public IExpression
{
public:

	virtual void				SetLeftArg(Expression&& left) = 0;
	virtual void				SetLeftArg(const Expression& left) = 0;
	virtual const Expression&	GetLeftArg() const = 0;

	virtual void				SetRightArg(Expression&& right) = 0;
	virtual void				SetRightArg(const Expression& right) = 0;
	virtual const Expression&	GetRightArg() const = 0;
};

}