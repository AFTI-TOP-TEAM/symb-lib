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

#include <string>
#include <utility>

namespace parser {

class Location : public std::exception {
public:
    Location(std::string rest, size_t pos)
        : m_rest(std::move(rest))
        , m_pos(pos)
    {
    }

    [[nodiscard]] bool empty() const
    {
        return m_rest.empty();
    }

    [[nodiscard]] const char* what() const noexcept override
    {
        return "Parse error";
    }
	
private:
    std::string     m_rest;
    size_t          m_pos;
};
}
