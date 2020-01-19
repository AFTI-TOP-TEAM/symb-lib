//------------------------------------------------------------------------------
// IFunction.h
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

class IFunction
{
public:

	virtual ~IFunction() = default;
	IFunction() = default;

	virtual IFunction*	Derivate() const = 0;
	virtual IFunction*	Integrate() const = 0;

	virtual IFunction*	Execute() = 0;	

	virtual void		SetValues(const std::unordered_map<std::string, Real> &vals) = 0; 
	virtual Real		Compute() const = 0;
};

}
