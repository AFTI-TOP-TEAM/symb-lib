//------------------------------------------------------------------------------
// IUnaryFunction.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#include "IFunction.h"

#include <string>

namespace symb
{

class IUnaryFunction : public IFunction
{
public:

	IUnaryFunction() = default;
	virtual ~IUnaryFunction() = default;

	virtual void		SetArg(IFunction* arg) = 0;
	virtual IFunction*	GetArg() const = 0;
};

}