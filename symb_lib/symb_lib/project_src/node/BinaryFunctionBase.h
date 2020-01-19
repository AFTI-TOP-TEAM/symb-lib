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

	void		SetValues(const std::vector<const Const*> &vals) override; 
	Const*		Compute() const override;
	
protected:
	virtual IFunction*	ExecuteImpl(IFunction* leftExecuted, IFunction* rightExecuted) const = 0;
	virtual Const*		ComputeImpl(const Const* left, const Const* right) const = 0;

private:
	IFunction*	m_left;
	IFunction*	m_right;

	bool		m_hasValues;
};

}