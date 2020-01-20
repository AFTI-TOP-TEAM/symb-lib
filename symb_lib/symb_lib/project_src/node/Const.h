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
	Const(Real val = 0, const std::string& label = "", bool isVariable = false);

	virtual ~Const() = default;

	// IExpression
	Expression		Derivate() const final;

	Expression		Execute() final;
	
	Expression		Copy() const final;
	Expression		RowExpression() const final;

	bool			IsOptimized() const final;
	void			SetOptimized(bool optimized) final;

	Real			Compute() const final;

	void			SetValues(const std::unordered_map<std::string, Real>& vals) final;
	
	void			SetLabel(const std::string &label);
	std::string		GetLabel() const;
	void			SetVal(Real val);
	
	bool			IsVariable() const;

private:
	Real			m_val;
	std::string		m_label;

	bool			m_isVariable;
};

}