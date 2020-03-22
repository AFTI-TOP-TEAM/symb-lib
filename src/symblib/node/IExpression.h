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

#include "symblib/Types.h"

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

	[[nodiscard]] virtual Expression		Copy() const = 0;
	[[nodiscard]] virtual Expression		RowExpression() const = 0;
	
	[[nodiscard]] virtual bool				IsOptimized() const = 0;
	virtual void			SetOptimized(bool optimized) = 0;

	virtual std::string		GetType() const = 0;
};
	
}
