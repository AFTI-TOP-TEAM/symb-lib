#include "BinaryExpressionBase.h"

namespace symb
{
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetLeftArg(IExpression* left)
{
	m_left = left;
}
//-----------------------------------------------------------------------------------------
IExpression* BinaryExpressionBase::GetLeftArg() const 
{
	return m_left;
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetRightArg(IExpression* right)
{
	m_right = right;
}
//-----------------------------------------------------------------------------------------
IExpression* BinaryExpressionBase::GetRightArg() const 
{
	return m_right;
}
//-----------------------------------------------------------------------------------------
IExpression* BinaryExpressionBase::Execute() const 
{
	return ExecuteImpl(m_left->Execute(), m_right->Execute());
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetValues(const std::unordered_map<std::string, Real> &vals)
{
	m_left->SetValues(vals);
	m_right->SetValues(vals);
}
//-----------------------------------------------------------------------------------------
Real BinaryExpressionBase::Compute() const 
{
	return ComputeImpl(m_left->Compute, m_right->Compute());
}
//-----------------------------------------------------------------------------------------
}


