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
#include <memory>

class ExpressionBase;

namespace symb {
// Unimplemented
class Empty : public ExpressionBase {
    Empty() = default;
    virtual ~Empty() = default;
};
}
