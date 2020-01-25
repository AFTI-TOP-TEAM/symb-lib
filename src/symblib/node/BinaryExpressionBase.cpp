#include "BinaryExpressionBase.h"
#include "Var.h"

namespace symb
{
//-----------------------------------------------------------------------------------------	
BinaryExpressionBase::BinaryExpressionBase(Expression&& left, Expression&& right)
	: m_left(std::move(left))
	, m_right(std::move(right))
{
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetLeftArg(Expression&& left)
{
	m_left = std::move(left);
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetLeftArg(const Expression& left)
{
	SetLeftArg(left->Copy());
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetRightArg(const Expression& right)
{
	SetRightArg(right->Copy());
}
//-----------------------------------------------------------------------------------------
const Expression& BinaryExpressionBase::GetLeftArg() const
{
	return m_left;
}
//-----------------------------------------------------------------------------------------
Expression&& BinaryExpressionBase::ReleaseLeftArg()
{
	return std::move(m_left);
}
//-----------------------------------------------------------------------------------------
Expression&& BinaryExpressionBase::ReleaseRightArg()
{
	return std::move(m_right);
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetRightArg(Expression&& right)
{
	m_right = std::move(right);
}
//-----------------------------------------------------------------------------------------
const Expression& BinaryExpressionBase::GetRightArg() const
{
	return m_right;
}
//-----------------------------------------------------------------------------------------
Expression BinaryExpressionBase::Copy() const
{
	return CopyImpl(m_left->Copy(), m_right->Copy());
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetValues(const std::unordered_map<std::string, Real> &vals)
{
	m_left->SetValues(vals);
	m_right->SetValues(vals);
}
//-----------------------------------------------------------------------------------------
}


