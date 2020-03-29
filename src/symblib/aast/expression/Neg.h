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

class Neg final : public NthExpression<Neg, 1>
{
    using Base = NthExpression<Neg, 1>;
public:
    Neg();
    explicit Neg(Expression&& expr);
    explicit Neg(const Expression& expr);
    explicit Neg(Arguments&& values);
	
    Neg(const Neg&) = delete;
	
    Neg operator=(const Neg&) = delete;
    Neg operator=(Neg&&) = delete;
};

}
