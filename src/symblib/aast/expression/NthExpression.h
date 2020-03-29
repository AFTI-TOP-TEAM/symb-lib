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
#include <array>

namespace symb
{

template <typename TExpression, size_t ArgCount>
class NthExpression : public ExpressionBase<TExpression, std::array<Expression, ArgCount>>, public IExpressionHolder
{
public:
	using Arguments = std::array<Expression, ArgCount>;
	
	virtual ~NthExpression() = default;

	explicit NthExpression(ExpressionType type, Arguments&& value);
	explicit NthExpression(ExpressionType type, std::initializer_list<Expression>&& value);
	explicit NthExpression(ExpressionType type);
	
	// IExpression
	[[nodiscard]] Expression		Copy() const final;
	
	void	SetValues(const std::unordered_map<std::string, Real>& vals) final;

	// IExpressionHolder
	void	SetArg(Expression&& arg, size_t rank) final;
	void	SetArgs(std::vector<Expression>&& args) final;
	
	[[nodiscard]] const Expression&		GetArg(size_t rank) const final;
	[[nodiscard]] Expression&			GetArg(size_t rank) final;
	[[nodiscard]] size_t				Rank() const final;

private:
	using Base = ExpressionBase<TExpression, Arguments>;
};

template <typename TExpression, size_t ArgCount>
NthExpression<TExpression, ArgCount>::NthExpression(ExpressionType type, Arguments&& value)
	: Base(type, std::move(value))
{
}

template <typename TExpression, size_t ArgCount>
NthExpression<TExpression, ArgCount>::NthExpression(ExpressionType type, std::initializer_list<Expression>&& value)
	: Base(type)
{
	size_t i = 0;
	for (auto&& arg : value)
	{
		m_value[i] = std::move(arg);
		++i;
	}
}

template <typename TExpression, size_t ArgCount>
NthExpression<TExpression, ArgCount>::NthExpression(ExpressionType type)
	: Base(type)
{
}

template <typename TExpression, size_t ArgCount>
Expression NthExpression<TExpression, ArgCount>::Copy() const
{
	Arguments copies;
	for(size_t i = 0; i < m_value.size(); ++i)
		copies[i] = m_value[i]->Copy();

	return MakeExpression<TExpression>(std::move(copies));
}

template <typename TExpression, size_t ArgCount>
void NthExpression<TExpression, ArgCount>::SetValues(const std::unordered_map<std::string, Real>& vals)
{
	for (const auto& exp : m_value)
		exp->SetValues(vals);
}

template <typename TExpression, size_t ArgCount>
void NthExpression<TExpression, ArgCount>::SetArg(Expression&& arg, size_t rank)
{
	assert(rank >= m_value.size());
	m_value[rank] = std::move(arg);
}

template <typename TExpression, size_t ArgCount>
void NthExpression<TExpression, ArgCount>::SetArgs(std::vector<Expression>&& args)
{
	for (size_t i = 0; i < m_value.size(); ++i)
		m_value[i] = std::move(args[i]);
}

template <typename TExpression, size_t ArgCount>
const Expression& NthExpression<TExpression, ArgCount>::GetArg(size_t rank) const
{
	assert(rank >= m_value.size());
	return m_value[rank];
}

template <typename TExpression, size_t ArgCount>
Expression& NthExpression<TExpression, ArgCount>::GetArg(size_t rank)
{
	assert(rank >= m_value.size());
	return m_value[rank];
}

template <typename TExpression, size_t ArgCount>
size_t NthExpression<TExpression, ArgCount>::Rank() const
{
	return m_value.size();
}
	
}
