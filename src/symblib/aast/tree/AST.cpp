#include "AST.h"

namespace symb
{
//------------------------------------------------------------------------------	
AST::AST(Expression&& exp)
	: m_root(std::move(exp))
{
}
//------------------------------------------------------------------------------
NodeIterator AST::begin() const
{
	return NodeIterator(m_root.get());
}
//------------------------------------------------------------------------------
NodeIterator AST::end() const 
{
	return NodeIterator(nullptr);
}
//------------------------------------------------------------------------------
}
