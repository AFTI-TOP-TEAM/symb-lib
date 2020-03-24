#include "NodeIterator.h"

#include "aast/expression/Var.h"
#include "aast/expression/NthExpression.h"

namespace symb
{
//------------------------------------------------------------------------------
NodeIterator::NodeIterator(IExpression* expr)
	: m_node(expr)
{
	// TODO:: add lazy initialization optimization
	if(m_node != nullptr)
		m_node = DropLeft(m_node);
}
//------------------------------------------------------------------------------
NodeIterator& NodeIterator::operator=(const NodeIterator& itr)
{
	m_node = itr.m_node;
	m_trace = itr.m_trace;
	
	return *this;
}
//------------------------------------------------------------------------------
NodeIterator& NodeIterator::operator=(NodeIterator&& itr)
{
	m_node = itr.m_node;
	m_trace = itr.m_trace;

	itr.m_node = nullptr;
	itr.m_trace.clear();
	
	return *this;
}
//------------------------------------------------------------------------------
NodeIterator NodeIterator::operator++()
{
	if (m_node == nullptr) return *this;

	if (m_trace.empty())
	{
		// it means now we located at the root node and have to drop to the right sub tree
		// if it exists
		//if (const auto node = dynamic_cast<BinaryExpressionBase*>(m_node))
		//	m_node = DropLeft(node->GetRightArg().get());
		//else
		//	m_node = nullptr;
		
		return *this;
	}

	for(;;)
	{
		if(m_trace.empty())
		{
			m_node = nullptr;
			return *this;
		}
		
		const auto root = m_trace.back();

	/*	if (dynamic_cast<UnaryExpressionBase*>(root))
		{
			m_node = root;
			m_trace.pop_back();
			return *this;
		}*/

		/*if (const auto node = dynamic_cast<BinaryExpressionBase*>(root))
		{
			if (m_node == node->GetLeftArg().get())
			{
				m_node = DropLeft(node->GetRightArg().get());
				return *this;
			}

			if (m_node == node->GetRightArg().get())
			{
				m_node = node;
				m_trace.pop_back();
				return *this;
			}
		}*/
	}
}
//------------------------------------------------------------------------------	
IExpression* NodeIterator::DropLeft(IExpression* exp)
{
	if (m_node == nullptr) return nullptr;
	
	auto node = exp;
	for (;;)
	{
		if (const auto var = dynamic_cast<Var*>(node))
			return var;

		m_trace.push_back(node);
		node = node->As<IExpressionHolder>()->GetArg(0).get();
	}
}
//------------------------------------------------------------------------------
bool NodeIterator::operator==(const NodeIterator& rhs) const
{
	return m_node == rhs.m_node;
}
//------------------------------------------------------------------------------
bool NodeIterator::operator!=(const NodeIterator& rhs) const
{
	return m_node != rhs.m_node;
}
//------------------------------------------------------------------------------
IExpression* NodeIterator::operator->() const
{
	return m_node;
}
//------------------------------------------------------------------------------
IExpression* NodeIterator::operator*() const
{
	return m_node;
}
//------------------------------------------------------------------------------
}
