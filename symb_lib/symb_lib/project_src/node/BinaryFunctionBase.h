//------------------------------------------------------------------------------
// BinaryFunctionBase.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#include "IBinaryFunction.h"

namespace symb
{

class BinaryFunctionBase : public IBinaryFunction
{
public:
	void		SetLeftArg(IFunction* left) override;
	IFunction*	GetLeftArg() const override;

	void		SetRightArg(IFunction* right) override;
	IFunction*	GetRightArg() const override;

	IFunction*	Execute() override;	

	void		SetValues(const std::unordered_map<std::string, Real> &vals) override; 
	Real		Compute() const override;
	
protected:
	virtual IFunction*	ExecuteImpl(IFunction* leftExecuted, IFunction* rightExecuted) const = 0;
	virtual Real		ComputeImpl(Real left, Real right) const = 0;

private:
	IFunction*	m_left;
	IFunction*	m_right;
};

}