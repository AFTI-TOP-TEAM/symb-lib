//------------------------------------------------------------------------------
// UnaryFunctionBase.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#include "IUnaryFunction.h"

namespace symb
{

class UnaryFunctionBase : public IUnaryFunction
{
public:
	void		SetArg(IFunction* arg) override;
	IFunction*	GetArg() const override;

	IFunction*	Execute() override;	

	void		SetValues(const std::unordered_map<std::string, Real> &vals) override; 
	Real		Compute() const override;

protected:
	virtual IFunction*	ExecuteImpl(const IFunction* argExecuted) const = 0;
	virtual Real		ComputeImpl(const Const* arg) const = 0;

private:
	IFunction*		m_arg;

	std::string		m_label;
};

}