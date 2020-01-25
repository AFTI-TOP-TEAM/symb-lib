#include "NodeIterator.h"

namespace symb
{
//------------------------------------------------------------------------------
NodeIterator::NodeIterator(const Expression& expr)
	: m_this(expr.get())
{
}
//------------------------------------------------------------------------------
NodeIterator& NodeIterator::operator=(const NodeIterator& itr)
{
	m_this = itr.m_this;
	m_root = itr.m_root;
	
	return *this;
}
//------------------------------------------------------------------------------
NodeIterator& NodeIterator::operator=(NodeIterator&& itr) noexcept
{
	m_this = itr.m_this;
	m_root = itr.m_root;
	m_state = itr.m_state;

	itr.m_this = nullptr;
	itr.m_root = nullptr;
	
	return *this;
}
//------------------------------------------------------------------------------
NodeIterator NodeIterator::operator++() const
{
	if(m_state == State::InLeft)
	
	return *this;
}
//------------------------------------------------------------------------------
NodeIterator& NodeIterator::operator++(int)
{
	return *this;
}
//------------------------------------------------------------------------------
bool NodeIterator::operator==(const NodeIterator& rhs) const
{
	return m_this == rhs.m_this;
}
//------------------------------------------------------------------------------
bool NodeIterator::operator!=(const NodeIterator& rhs) const
{
	return m_this != rhs.m_this;
}
//------------------------------------------------------------------------------
//Expression* NodeIterator::operator->()
//{
//	return nullptr;
//}
////------------------------------------------------------------------------------
}
