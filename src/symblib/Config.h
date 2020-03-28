//------------------------------------------------------------------------------
// Types.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       26.03.20
// Author:     glensand
//------------------------------------------------------------------------------

#pragma once

#include <memory>

namespace symb
{

constexpr auto USE_ARENA_ALLOCATOR { false };
constexpr auto USE_CUSTOM_ALLOCATOR = { false };
constexpr auto USE_SHARED{ true };

class IExpression;
using Expression = std::shared_ptr<IExpression>;

}
