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
using Expression = std::shared_ptr<IExpression>;

enum class ExpressionType : unsigned char;
	
class IExpression
{
public:

	virtual ~IExpression() = default;
	IExpression() = default;

	virtual void							SetValues(const std::unordered_map<std::string, Real>& vals) = 0;

	[[nodiscard]] virtual Expression		Copy() const = 0;
	[[nodiscard]] virtual Expression		RowExpression() const = 0;
	
	[[nodiscard]] virtual bool				IsOptimized() const = 0;
	virtual void							SetOptimized(bool optimized) = 0;

	[[nodiscard]] virtual ExpressionType	Type() const = 0;

	template <typename TExpression>
	TExpression* As();

	template <typename TExpression>
	constexpr TExpression* AsSafe();
};

template <typename TExpression>
TExpression* IExpression::As()
{
	return reinterpret_cast<TExpression*>(this);
}

template <typename TExpression>
constexpr TExpression* IExpression::AsSafe()
{
	static_assert(std::is_convertible_v<TExpression&, IExpression&>);
	return static_cast<TExpression*>(this);
}

template <typename TExpression, typename ...Args>
Expression	MakeExpression(Args&&... args)
{
	return std::static_pointer_cast<IExpression>(
		std::make_shared<TExpression>(std::forward<Args>(args)...)
			);
}
	
}
