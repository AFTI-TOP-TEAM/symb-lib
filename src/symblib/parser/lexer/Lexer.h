//------------------------------------------------------------------------------
// Lexer.h
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       2020-03-22
// Author:     minium2
//------------------------------------------------------------------------------
#pragma once

#include "symblib/parser/lexer/Token.h"
#include <string>
#include <vector>

class Lexer {
public:
    Lexer(const std::string input)
        : m_input(input)
        , m_pos(0)
        , m_currentTok(TokenKind::NONE)
    {
	    // ReSharper disable once CppNoDiscardExpression
	    nextToken();
    }

    [[nodiscard]] Token token() const noexcept
    {
        return m_currentTok;
    }
    ///
    /// \brief nextToken
    /// \return next token in stream
    ///
    [[nodiscard]] Token nextToken();
    ///
    /// \brief position
    /// \return position of the undecoded remainder
    ///
    [[nodiscard]] size_t position() const noexcept
    {
        const auto s = m_currentTok.m_str;
        return m_pos - (s.empty() ? 1 : s.length());
    }
    ///
    /// \brief getStore
    /// \return the undecoded remainder of the text
    ///
    [[nodiscard]] const char* getStore() const
    {
        return m_input.c_str() + position();
    }
    ///
    /// \brief getAllToken
    /// \return all tokens as vector
    ///
    std::vector<Token> getAllToken();

private:
    Token nextTokenImpl();

    std::string     m_input;
    size_t          m_pos;
    Token           m_currentTok;
};
