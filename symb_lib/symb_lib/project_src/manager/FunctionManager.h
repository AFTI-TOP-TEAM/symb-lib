//------------------------------------------------------------------------------
// ExpressionManager.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------
#pragma once

#include <memory>
#include "../node/IExpression.h"

namespace symb
{

template <typename T, typename... Args>
Expression MakeExpression(Args&&... args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
}

}