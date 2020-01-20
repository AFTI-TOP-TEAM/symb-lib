//------------------------------------------------------------------------------
// BinaryExpressionBase.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------
#pragma once

#include "IBinaryExpression.h"

namespace symb
{

class BinaryExpressionBase : public IBinaryExpression
{
public:

	virtual ~BinaryExpressionBase() = default;
	BinaryExpressionBase(Expression&& left, Expression&& right);
	
	void				SetLeftArg(Expression&& left) final;
	void				SetLeftArg(const Expression& left) final;
	const Expression&	GetLeftArg() const final;

	void				SetRightArg(Expression&& right) final;
	void				SetRightArg(const Expression& right) final;
	const Expression&	GetRightArg() const final;

	Expression			Execute() final;	

	void				SetValues(const std::unordered_map<std::string, Real> &vals) final; 

	Real				Compute() const final;

	Expression			Derivate() const final;
	
	Expression			Copy() const final;

protected:
	void				SetOptimized(bool optimized);
	bool				IsOptimized() const;
	
	virtual Real		ComputeImpl(Real left, Real right) const = 0;

	virtual Expression	ExecuteImpl() = 0;

	virtual Expression	DerivateImpl(Expression&& left, Expression&& right) const = 0;

	virtual Expression	CopyImpl(Expression&& left, Expression&& right) const = 0;
	
private:
	Expression	m_left;
	Expression	m_right;

	bool		m_isOptimized{ false };
};

}