//------------------------------------------------------------------------------
// BinaryExpressionBase.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#include "IBinaryExpression.h"

namespace symb
{

class BinaryExpressionBase : public IBinaryExpression
{
public:
	void		SetLeftArg(IExpression* left) override;
	IExpression*	GetLeftArg() const override;

	void		SetRightArg(IExpression* right) override;
	IExpression*	GetRightArg() const override;

	IExpression*	Execute() override;	

	void		SetValues(const std::unordered_map<std::string, Real> &vals) override; 
	Real		Compute() const override;
	
protected:
	virtual IExpression*	ExecuteImpl(IExpression* leftExecuted, IExpression* rightExecuted) const = 0;
	virtual Real		ComputeImpl(Real left, Real right) const = 0;

private:
	IExpression*	m_left;
	IExpression*	m_right;
};

}