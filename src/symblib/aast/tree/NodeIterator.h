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

#include <list>

namespace symb
{

class IExpression;
	
class NodeIterator final
{
public:

	NodeIterator() = delete;
	~NodeIterator() = default;

	explicit NodeIterator(IExpression* expr);

	NodeIterator(const NodeIterator&) = default;
	NodeIterator(NodeIterator&&) = default;
	
	NodeIterator& operator=(const NodeIterator&);
	NodeIterator& operator=(NodeIterator&&) noexcept;
	
    NodeIterator operator++();
    //NodeIterator& operator++(int);

	bool operator==(const NodeIterator& rhs) const;
	bool operator!=(const NodeIterator& rhs) const;
	
	IExpression* operator->() const;
	IExpression* operator*() const;

private:

	IExpression*	DropLeft(IExpression* exp);
	
	IExpression*				m_node{ nullptr };
	std::list<IExpression*>		m_trace;
};

}
