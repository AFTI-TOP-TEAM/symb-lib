//------------------------------------------------------------------------------
// AstWalker.h
//
// AstWalker implements. Convert Iast nodes to Expression
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 25.01.2020
// Author: minium2
//------------------------------------------------------------------------------
#pragma once
#include "Iast.h"
#include "Walker.h"

#include "manager/ExpressionManager.h"


namespace ast {

class AstWalker: public Walker<symb::Expression> {
public:
    symb::Expression operator()(ast::Nil) const override;

    symb::Expression operator()(double n) const override;

    symb::Expression operator()(ast::Operation const& x, symb::Expression lhs) const override;

    symb::Expression operator()(ast::Signed const& x) const override;

    symb::Expression operator()(ast::Program const& x) const override;

    symb::Expression operator()(ast::Function const& n) const override;

    static symb::Expression convertToExpression(const ast::Program& iast) {
        return AstWalker()(iast);
    }
};

}
