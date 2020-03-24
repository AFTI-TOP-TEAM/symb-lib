//------------------------------------------------------------------------------
// Neg.h
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 25.01.2020
// Author: minium2
//------------------------------------------------------------------------------
#pragma once

#include "NthExpression.h"

namespace symb
{

class Neg final : public NthExpression<Neg>
{
public:
    Neg();
    explicit Neg(Expression&& expr);
    explicit Neg(const Expression& expr);
    explicit Neg(std::vector<Expression>&& values);
	
    Neg(const Neg&) = delete;
	
    Neg operator=(const Neg&) = delete;
    Neg operator=(Neg&&) = delete;
};

}
