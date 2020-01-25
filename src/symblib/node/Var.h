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

class Var : public IExpression
{

public:
	Var(const std::string& label, Real val = 0, bool isVariable = true);

	virtual ~Var() = default;

	// IExpression	
	Expression		Copy() const final;
	Expression		RowExpression() const final;

	bool			IsOptimized() const final;
	void			SetOptimized(bool optimized) final;
	
	void			SetValues(const std::unordered_map<std::string, Real>& vals) final;
	
	void			SetLabel(const std::string &label);
	std::string		GetLabel() const;
	void			SetVal(Real val);
	
	bool			IsVariable() const;

	std::string		GetType() const override;
private:
	Real			m_val;
	std::string		m_label;

	bool			m_isVariable;
};

}