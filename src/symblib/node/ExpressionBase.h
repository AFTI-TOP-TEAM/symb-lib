//------------------------------------------------------------------------------
// ExpressionBase.h
//
// ExpressionBase implements...
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 21.01.2020
// Author: Bezborodov Gleb
//------------------------------------------------------------------------------
#pragma once

#include "IExpression.h"

namespace symb {

class ExpressionBase : public IExpression {
public:
    ExpressionBase() = default;
    virtual ~ExpressionBase() = default;

    bool IsOptimized() const final;
    void SetOptimized(bool optimized) final;

private:
    bool m_optimized{ false };
};
}
