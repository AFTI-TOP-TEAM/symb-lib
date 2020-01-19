//------------------------------------------------------------------------------
// IExpression.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#include <unordered_map>
#include <string>

#include "project_src/Types.h"

namespace symb
{

class IExpression
{
public:

	virtual ~IExpression() = default;
	IExpression() = default;

	virtual IExpression*	Derivate() const = 0;
	virtual IExpression*	Integrate() const = 0;

	virtual IExpression*	Execute() = 0;	

	virtual void		SetValues(const std::unordered_map<std::string, Real> &vals) = 0; 
	virtual Real		Compute() const = 0;
};

}
