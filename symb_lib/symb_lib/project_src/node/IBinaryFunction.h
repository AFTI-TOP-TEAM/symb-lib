//------------------------------------------------------------------------------
// IBinaryFunction.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#include "IFunction.h"

namespace symb
{

class IBinaryFunction : public IFunction
{
public:

	virtual void		SetLeftArg(IFunction* left) = 0;
	virtual IFunction*	GetLeftArg() const = 0;

	virtual void		SetRightArg(IFunction* right) = 0;
	virtual IFunction*	GetRightArg() const = 0;
};

}