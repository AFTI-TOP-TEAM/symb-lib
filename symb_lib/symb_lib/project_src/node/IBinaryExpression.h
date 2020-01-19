//------------------------------------------------------------------------------
// IBinaryExpression.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#include "IExpression.h"

namespace symb
{

class IBinaryExpression : public IExpression
{
public:

	virtual void		SetLeftArg(IExpression* left) = 0;
	virtual IExpression*	GetLeftArg() const = 0;

	virtual void		SetRightArg(IExpression* right) = 0;
	virtual IExpression*	GetRightArg() const = 0;
};

}