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

	void		SetValues(const std::vector<const Const*> &vals) override; 
	Const*		Compute() const override;

	void		SetLabel(const std::string &label);
	std::string	GetLabel() const;

protected:
	virtual IFunction*	ExecuteImpl(const IFunction* argExecuted) const = 0;
	virtual Const*		ComputeImpl(const Const* arg) const = 0;

private:
	IFunction*		m_arg;

	std::string		m_label;
	bool			m_hasValues;
};

}