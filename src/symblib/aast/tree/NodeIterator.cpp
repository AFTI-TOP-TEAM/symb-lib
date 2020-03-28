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
NodeIterator& NodeIterator::operator=(NodeIterator&& itr) noexcept
{
	m_node = itr.m_node;
	m_trace = itr.m_trace;

	itr.m_node = nullptr;
	try
	{
		itr.m_trace.clear();
	}
	catch (const std::exception& ex)
	{
		// ignore
	}
	
	
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
		if (const auto node = dynamic_cast<IExpressionHolder*>(m_node))
			m_node = DropLeft(node->GetArg(1).get());
		else
			m_node = nullptr;
		
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

		auto holder = root->As<IExpressionHolder>();
		if (holder->Rank() == 1)
		{
			m_node = root;
			m_trace.pop_back();
			return *this;
		}

		
		if (m_node == holder->GetArg(0).get())
		{
			m_node = DropLeft(holder->GetArg(1).get());
			return *this;
		}

		if (m_node == holder->GetArg(0).get())
		{
			m_node = reinterpret_cast<IExpression*>(holder);
			m_trace.pop_back();
			return *this;
		}

		// TODO:: add ternary operation compatibility
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
