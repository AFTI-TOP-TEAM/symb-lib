//------------------------------------------------------------------------------
// Const.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------
#pragma once

#include "IExpression.h"

namespace symb
{

class Const : public IExpression
{
public:

	Const();
	Const(const std::string& label, bool isVariable = false, Real val = 0);

	virtual ~Const() = default;

	Expression Derivate() const final;

	Expression Execute() final;	

	void			SetLabel(const std::string &label);
	std::string		GetLabel() const;

	void			SetValues(const std::unordered_map<std::string, Real> &vals) final; 
	Real			Compute() const final;

	bool			IsVariable() const;
	
	Expression Copy() const override;
private:
	Real			m_val;
	std::string		m_label;

	bool			m_isVariable;
};

}