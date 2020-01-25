//------------------------------------------------------------------------------
// NodeIterator.h
//
// NodeIterator implements...
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 25.01.2020
// Author: glensand
//------------------------------------------------------------------------------
#pragma once

#include "IExpression.h"
#include <list>

namespace symb
{

class NodeIterator final
{
public:

	NodeIterator() = delete;
	~NodeIterator() = default;

	explicit NodeIterator(const Expression& expr);

	NodeIterator(const NodeIterator&) = default;
	NodeIterator(NodeIterator&&) = default;
	
	NodeIterator& operator=(const NodeIterator&);
	NodeIterator& operator=(NodeIterator&&) noexcept;
	
    NodeIterator operator++() const;
    NodeIterator& operator++(int);

	bool operator==(const NodeIterator& rhs) const;
	bool operator!=(const NodeIterator& rhs) const;
	
	IExpression* operator->();

private:

	enum class State
	{
		InRoot,
		InLeft,
		InRight
	};
	
	IExpression*		m_this{ nullptr };
	IExpression*		m_root{ nullptr };

	State				m_state{ State::InRoot };
};

}
