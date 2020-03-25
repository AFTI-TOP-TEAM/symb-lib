//------------------------------------------------------------------------------
// IExpressionHolder.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------
#pragma once

#include <memory>
#include <vector>

namespace symb
{

class IExpression;
using Expression = std::shared_ptr<IExpression>;
	
class IExpressionHolder
{
public:

	virtual ~IExpressionHolder() = default;
	IExpressionHolder() = default;

	virtual void	SetArg(Expression&& arg, size_t rang) = 0;
	virtual void	SetArgs(std::vector<Expression>&& args) = 0;

	[[nodiscard]] virtual const Expression& GetArg(size_t rang) const = 0;
	[[nodiscard]] virtual Expression&		GetArg(size_t rang) = 0;
	[[nodiscard]] virtual size_t			Rang() const = 0;
};
	
}
