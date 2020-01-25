//------------------------------------------------------------------------------
// Grammar.h
//
// Abstract Walker for iast traversal.
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 25.01.2020
// Author: minium2
//------------------------------------------------------------------------------
#pragma once
#include "Iast.h"

namespace ast {

template<typename Type>
class Walker {
public:
    virtual Type operator()(ast::Nil) const = 0;

    virtual Type operator()(double n) const = 0;

    virtual Type operator()(ast::Operation const& x, Type lhs) const = 0;

    virtual Type operator()(ast::Signed const& x) const = 0;

    virtual Type operator()(ast::Program const& x) const = 0;

    virtual Type operator()(ast::Function const& n) const = 0;
};

}
