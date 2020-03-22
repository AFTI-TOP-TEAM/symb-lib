//------------------------------------------------------------------------------
// UnaryExpressionBase.h
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------
#pragma once

#include "ExpressionBase.h"

namespace symb {

class UnaryExpressionBase : public ExpressionBase {
public:
    UnaryExpressionBase() = default;

    virtual ~UnaryExpressionBase() = default;

    explicit UnaryExpressionBase(Expression&& expr);

    // IExpression
    void SetValues(const std::unordered_map<std::string, Real>& vals) final;

    Expression Copy() const final;

    //Own methods
    virtual void SetArg(Expression&& arg) final;
    virtual void SetArg(const Expression& arg) final;
    virtual const Expression& GetArg() const final;
    virtual Expression&& ReleaseArg() final;

protected:
    virtual Expression CopyImpl(Expression&& expression) const = 0;

private:
    Expression m_arg;
};

using UnaryExpression = std::unique_ptr<UnaryExpressionBase>;
}
