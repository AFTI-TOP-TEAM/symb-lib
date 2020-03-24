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

#include "ExpressionBase.h"

namespace symb
{

class Var : public ExpressionBase<Var, Real>
{

public:
	//Var construction/destruction
	explicit Var(std::string label, Real val = 0, bool isVariable = true);
	Var();

	Var(const Var&) = delete;
	Var(Var&&) = delete;

	Var operator=(Var&&) = delete;
	Var operator=(const Var&) = delete;
	
	virtual ~Var() = default;

	// IExpression
	void							SetValues(const std::unordered_map<std::string, Real>& vals) final;
	void							SetVal(Real val);
	
	[[nodiscard]] Expression		Copy() const final;

	[[nodiscard]] std::string		GetLabel() const;
	void							SetLabel(const std::string &label);
	
private:
	std::string		m_label;

	bool			m_isVariable;
};

}