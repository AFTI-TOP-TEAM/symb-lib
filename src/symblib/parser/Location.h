//------------------------------------------------------------------------------
// Location.h
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       2020-03-22
// Author:     minium2
//------------------------------------------------------------------------------
#pragma once

#include <memory>
#include <string>

#include "symblib/parser/lexer/Lexer.h"

namespace parser {

class Location : public std::exception {
public:
    Location(const std::string& rest, size_t pos)
        : m_rest(rest)
        , m_pos(pos)
    {
    }

    inline bool empty() const
    {
        return m_rest.empty();
    }

    const char* what() const noexcept override
    {
        return "Parse error";
    }
    std::string m_rest;
    size_t m_pos;
};
}
