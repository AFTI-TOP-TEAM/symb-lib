//------------------------------------------------------------------------------
// Token.h
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       2020-03-22
// Author:     minium2
//------------------------------------------------------------------------------
#pragma once

#include <string>
#include <utility>

enum class TokenKind {
    NONE = 'N',
    PLUS = '+',
    MINUS = '-',
    MULT = '*',
    DIV = '/',
    POW = '^',
    IDENTIFIER = 'i',
    NUMBER = 'd',
    LEFT_BRACKET = '(',
    RIGHT_BRACKET = ')',
    LEFT_BRACE = '{',
    RIGHT_BRACE = '}'
};

struct Token {
    Token(TokenKind tokenKind, std::string str = "")
        : m_str(std::move(str))
        , m_tokenKind(tokenKind)
    {
    }
    std::string     m_str;
    TokenKind       m_tokenKind;
};
