//------------------------------------------------------------------------------
// ExpressionBase.h
//
// ExpressionBase implements...
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 21.01.2020
// Author: Bezborodov Gleb
//------------------------------------------------------------------------------
#pragma once

#include "IExpression.h"
#include "symblib/classlib/utils.h"

namespace symb
{

enum class ExpressionCategory : unsigned char;
	
// CRTP
template <typename TExpression, typename TExpressionValue>
class ExpressionBase : public IExpression
{
public:

	explicit ExpressionBase(ExpressionType type);
	
	template <typename TValue>
	ExpressionBase(ExpressionType type, TValue&& value);
	virtual ~ExpressionBase() = default;

	template <typename TValue>
	void SetValue(TValue&& value);
	
	[[nodiscard]] bool				IsOptimized() const final;

	void							SetOptimized(bool optimized) final;

	[[nodiscard]] Expression		RowExpression() const final;

	[[nodiscard]] ExpressionType	Type() const final;

protected:
	TExpressionValue			m_value;
	
private:
	bool						m_optimized{ false };
	ExpressionType				m_type{ };
	ExpressionCategory			m_category{ }; // is it required
};

template <typename TExpression, typename TExpressionValue>
ExpressionBase<TExpression, TExpressionValue>::ExpressionBase(ExpressionType type)
	: m_type(type)
{
}

template <typename TExpression, typename TExpressionValue>
template <typename TValue>
ExpressionBase<TExpression, TExpressionValue>::ExpressionBase(ExpressionType type, TValue&& value)
	: m_value(std::forward<TValue>(value))
	, m_type(type)
{
	//static_assert(std::is_constructible_v<TExpression, TValue>);
}

template <typename TExpression, typename TExpressionValue>
template <typename TValue>
void ExpressionBase<TExpression, TExpressionValue>::SetValue(TValue&& value)
{
	m_value = std::forward<TValue>(value);
}

template <typename TExpression, typename TExpressionValue>
bool ExpressionBase<TExpression, TExpressionValue>::IsOptimized() const
{
	return m_optimized;
}

template <typename TExpression, typename TExpressionValue>
void ExpressionBase<TExpression, TExpressionValue>::SetOptimized(bool optimized)
{
	m_optimized = optimized;
}
	
template <typename TExpression, typename TExpressionValue>
Expression ExpressionBase<TExpression, TExpressionValue>::RowExpression() const
{
	return MakeExpression<TExpression>();
}

template <typename TExpression, typename TExpressionValue>
ExpressionType ExpressionBase<TExpression, TExpressionValue>::Type() const
{
	return m_type;
}
	
}

