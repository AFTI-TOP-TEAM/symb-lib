//------------------------------------------------------------------------------
// Grammar.h
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 25.01.2020
// Author: minium2
//------------------------------------------------------------------------------
#pragma once

#include "node/UnaryExpressionBase.h"

namespace symb {

class Neg : public UnaryExpressionBase {
public:
    Neg() = default;

    Neg(Expression&& expr);

    std::string GetType() const override;

    Expression RowExpression() const override;

    Expression CopyImpl(Expression&& expression) const override;
};
}
