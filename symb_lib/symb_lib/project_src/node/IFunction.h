//------------------------------------------------------------------------------
// IFunction.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#include <vector>
#include <string>

namespace symb
{

class Const;

class IFunction
{
public:

	virtual ~IFunction() = default;
	IFunction() = default;

	virtual IFunction*	Derivative() const = 0;
	virtual IFunction*	Integrate() const = 0;

	virtual IFunction*	Execute() = 0;	

	virtual void		SetLabel(const std::string &label) = 0;
	virtual std::string	GetLabel() const = 0;

	virtual void		SetValues(const std::vector<const Const*> &vals) = 0; 
	virtual Const*		Compute() const = 0;
};

}
