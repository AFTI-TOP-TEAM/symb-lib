#include "BinaryFunctionBase.h"

namespace symb
{
//-----------------------------------------------------------------------------------------
void BinaryFunctionBase::SetLeftArg(IFunction* left)
{
	m_left = left;
}
//-----------------------------------------------------------------------------------------
IFunction* BinaryFunctionBase::GetLeftArg() const 
{
	return m_left;
}
//-----------------------------------------------------------------------------------------
void BinaryFunctionBase::SetRightArg(IFunction* right)
{
	m_right = right;
}
//-----------------------------------------------------------------------------------------
IFunction* BinaryFunctionBase::GetRightArg() const 
{
	return m_right;
}
//-----------------------------------------------------------------------------------------
IFunction* BinaryFunctionBase::Execute() const 
{
	return ExecuteImpl(m_left->Execute(), m_right->Execute());
}
//-----------------------------------------------------------------------------------------
void BinaryFunctionBase::SetValues(const std::unordered_map<std::string, Real> &vals)
{
	m_left->SetValues(vals);
	m_right->SetValues(vals);
}
//-----------------------------------------------------------------------------------------
Real BinaryFunctionBase::Compute() const 
{
	return ComputeImpl(m_left->Compute, m_right->Compute());
}
//-----------------------------------------------------------------------------------------
}


