//------------------------------------------------------------------------------
// UnaryExpressionBase.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------
#pragma once

#include "IUnaryExpression.h"

namespace symb
{

class UnaryExpressionBase : public IUnaryExpression
{
public:

	virtual ~UnaryExpressionBase() = default;
	explicit UnaryExpressionBase(Expression&& expr);
	
	void				SetArg(Expression&& arg) final;
	void				SetArg(const Expression& arg) final;
	const Expression&	GetArg() const final;

	void				SetValues(const std::unordered_map<std::string, Real> &vals) final; 

	Real				Compute() const final;

	Expression			Execute() final;
	
	Expression			Copy() const final;

	Expression			Derivate() const override;
	
protected:
	virtual Expression	DerivateImpl(Expression&& expression) const = 0;
	virtual Expression	CopyImpl(Expression&& expression) const = 0;

	virtual Expression	ExecuteImpl()= 0;

	virtual Real		ComputeImpl(Real arg) const = 0;

	void				SetOptimized(bool optimized);
	bool				IsOptimized() const;
	
private:
	Expression	m_arg;

	bool		m_optimized{ false };
};

}