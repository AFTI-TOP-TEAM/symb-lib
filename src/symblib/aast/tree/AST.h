//------------------------------------------------------------------------------
// AST.h
//
// AST implements...
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 29.01.2020
// Author: glensand
//------------------------------------------------------------------------------
#pragma once

#include "aast/expression/IExpression.h"
#include "NodeIterator.h"

namespace symb
{

class AST final
{
public:

	explicit AST(Expression &&);
	
	AST(const AST &) = delete;
	AST(AST &&) = default;
	
	AST operator=(const AST&) = delete;
	AST& operator=(AST&&) = default;
	
	~AST() = default;

	[[nodiscard]] NodeIterator	begin() const;
	[[nodiscard]] NodeIterator	end() const;
	
private:

	Expression	m_root;
};

}
