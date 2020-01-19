//------------------------------------------------------------------------------
// IExpression.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------
#pragma once

#include <unordered_map>
#include <string>
#include <memory>

#include "../Types.h"

namespace symb
{

class IExpression;
using Expression = std::unique_ptr<IExpression>;
	
class IExpression
{
public:

	virtual ~IExpression() = default;
	IExpression() = default;

	virtual void			SetValues(const std::unordered_map<std::string, Real>& vals) = 0;
	virtual Real			Compute() const = 0;

	virtual Expression	Execute() = 0;

	virtual Expression	Derivate() const = 0;

	virtual Expression	Copy() const = 0;

	//virtual Expression	Integrate() const = 0;
};
	
}
