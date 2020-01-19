//------------------------------------------------------------------------------
// IUnaryExpression.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#include "IExpression.h"

#include <string>

namespace symb
{

class IUnaryExpression : public IExpression
{
public:

	IUnaryExpression() = default;
	virtual ~IUnaryExpression() = default;

	virtual void		SetArg(IExpression* arg) = 0;
	virtual IExpression*	GetArg() const = 0;
};

}