//------------------------------------------------------------------------------
// UnaryExpressionBase.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#include "IUnaryExpression.h"

namespace symb
{

class UnaryExpressionBase : public IUnaryExpression
{
public:
	void		SetArg(IExpression* arg) override;
	IExpression*	GetArg() const override;

	IExpression*	Execute() override;	

	void		SetValues(const std::unordered_map<std::string, Real> &vals) override; 
	Real		Compute() const override;

protected:
	virtual IExpression*	ExecuteImpl(const IExpression* argExecuted) const = 0;
	virtual Real		ComputeImpl(const Const* arg) const = 0;

private:
	IExpression*		m_arg;

	std::string		m_label;
};

}