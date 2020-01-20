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

#include "ExpressionBase.h"

namespace symb
{

class BinaryProcessorBase;
	
class BinaryExpressionBase : public ExpressionBase
{
public:

	virtual ~BinaryExpressionBase() = default;
	BinaryExpressionBase(Expression&& left, Expression&& right);

	// IExpression
	Expression			Execute() final;	

	void				SetValues(const std::unordered_map<std::string, Real> &vals) final; 

	Real				Compute() const final;

	Expression			Derivate() const final;
	
	Expression			Copy() const final;

	//Own methods
	virtual void				SetLeftArg(Expression&& left) final;
	virtual void				SetLeftArg(const Expression& left) final;
	virtual const Expression&	GetLeftArg() const final;
	virtual Expression&&		ReleaseLeftArg()final;

	virtual void				SetRightArg(Expression&& right) final;
	virtual void				SetRightArg(const Expression& right) final;
	virtual const Expression&	GetRightArg() const final;
	virtual Expression&&		ReleaseRightArg()final;
protected:
	virtual Real				ComputeImpl(Real left, Real right) const = 0;

	virtual Expression			ExecuteImpl() = 0;

	virtual Expression			DerivateImpl(Expression&& left, Expression&& right) const = 0;

	virtual Expression			CopyImpl(Expression&& left, Expression&& right) const = 0;
	
private:
	Expression					m_left;
	Expression					m_right;

	friend BinaryProcessorBase;
};

using BinaryExpression = std::unique_ptr<BinaryExpressionBase>;

}