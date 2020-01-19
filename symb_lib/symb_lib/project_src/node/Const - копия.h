//------------------------------------------------------------------------------
// Const.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#include "IFunction.h"
#include "../Types.h"

namespace symb
{

class Const : public IFunction
{
public:

	Const();
	Const(Real val);

	virtual ~Const() = default; 

	IFunction*	Derivate() const final;
	IFunction*	Integrate() const final;

	IFunction*	Execute() final;	

	void		SetLabel(const std::string &label);
	std::string	GetLabel() const;

	void		SetValues(const std::unordered_map<std::string, Real> &vals) final; 
	Const*		Compute() final;

private:

	Real			m_val;
	std::string		m_label;

	bool			m_isVariable;
};

}