//------------------------------------------------------------------------------
// Parser.h
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       2020-03-15
// Author:     minium2
//------------------------------------------------------------------------------
#pragma once
#include "symblib/node/IExpression.h"
#include "symblib/parser/Location.h"
#include "symblib/parser/lexer/Lexer.h"

namespace parser {
class RecursiveParser {
public:
    void parse(Lexer& lex);

    inline symb::Expression getResult() const
    {
        return m_exp->Copy();
    }

private:
    symb::Expression m_exp;
};
}
