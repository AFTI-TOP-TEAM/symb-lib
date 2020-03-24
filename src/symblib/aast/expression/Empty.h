//------------------------------------------------------------------------------
// Empty.h
//
// Copyright (c) 2020 Afti
// All rights reserved.
// This class is plug for IExpression
// Date:       2020-03-22
// Author:     minium2
//------------------------------------------------------------------------------

#pragma once

#include "ExpressionBase.h"
#include "symblib/aast/expression/ExpressionType.h"

namespace symb {
// Unimplemented
class Empty final : public ExpressionBase<Empty, bool>
{
public:
    Empty()
		: ExpressionBase(ExpressionType::Empty)
    {
    }

    void SetValues(const std::unordered_map<std::string, Real>& vals) override{}
    [[nodiscard]] Expression Copy() const override { return MakeExpression<Empty>(); }
    virtual ~Empty() = default;
};
}
