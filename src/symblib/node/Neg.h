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

#include "UnaryExpressionBase.h"

namespace symb
{

class Neg final : public UnaryExpressionBase
{
public:
    Neg() = default;

    Neg(Expression&& expr);
    Neg(const Expression&) = delete;
	
    Neg operator=(const Expression&) = delete;
    Neg operator=(Expression&&) = delete;

    std::string     GetType() const override;

    Expression		RowExpression() const override;

    Expression      CopyImpl(Expression&& expression) const override;
};

}
