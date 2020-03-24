//------------------------------------------------------------------------------
// ExpressionType.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#pragma once

namespace symb
{

enum class ExpressionType : unsigned char
{
	Const,
	Diff,
	Div,
	Empty,
	Equality,
	Neg,
	Prod,
	Sum,
	Var,
};
	
}
