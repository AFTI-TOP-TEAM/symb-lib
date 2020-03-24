//------------------------------------------------------------------------------
// NthExpression.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------
#pragma once

#include "ExpressionBase.h"
#include "IExpressionHolder.h"

#include <cassert>
#include <initializer_list>

namespace symb
{

template <typename TExpression>
class NthExpression : public ExpressionBase<TExpression, std::vector<Expression>>, public IExpressionHolder
{
public:
	virtual ~NthExpression() = default;

	explicit NthExpression(ExpressionType type, std::vector<Expression>&& value);
	explicit NthExpression(ExpressionType type, std::initializer_list<Expression>&& value);
	explicit NthExpression(ExpressionType type);
	
	// IExpression
	[[nodiscard]] Expression		Copy() const final;
	
	void	SetValues(const std::unordered_map<std::string, Real>& vals) final;

	// IExpressionHolder
	void	SetArg(Expression&& arg, size_t rang) final;
	void	SetArgs(std::vector<Expression>&& args) final;
	
	[[nodiscard]] const Expression&	GetArg(size_t rang) const final;
	[[nodiscard]] Expression&		GetArg(size_t rang) final;
};

template <typename TExpression>
NthExpression<TExpression>::NthExpression(ExpressionType type, std::vector<Expression>&& value)
	: ExpressionBase(type, std::move(value))
{
}

template <typename TExpression>
NthExpression<TExpression>::NthExpression(ExpressionType type, std::initializer_list<Expression>&& value)
	: ExpressionBase(type)
{
	for (auto&& val : value)
		m_value.emplace_back(std::move(val));
}

template <typename TExpression>
NthExpression<TExpression>::NthExpression(ExpressionType type)
	: ExpressionBase(type)
{
}

template <typename TExpression>
Expression NthExpression<TExpression>::Copy() const
{
	std::vector<Expression> copies;
	for (const auto& arg : m_value)
		copies.emplace_back(arg->Copy());
	return MakeExpression<TExpression>(std::move(copies));
	//return Expression();
}

template <typename TExpression>
void NthExpression<TExpression>::SetValues(const std::unordered_map<std::string, Real>& vals)
{
	for (const auto& exp : m_value)
		exp->SetValues(vals);
}

template <typename TExpression>
void NthExpression<TExpression>::SetArg(Expression&& arg, size_t rang)
{
	assert(rang >= m_value.size());
	m_value[rang] = std::move(arg);
}

template <typename TExpression>
void NthExpression<TExpression>::SetArgs(std::vector<Expression>&& args)
{
	m_value = std::move(args);
}

template <typename TExpression>
const Expression& NthExpression<TExpression>::GetArg(size_t rang) const
{
	assert(rang >= m_value.size());
	return m_value[rang];
}

template <typename TExpression>
Expression& NthExpression<TExpression>::GetArg(size_t rang)
{
	assert(rang >= m_value.size());
	return m_value[rang];
}
}
