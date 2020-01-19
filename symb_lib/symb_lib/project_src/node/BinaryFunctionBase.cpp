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
void BinaryFunctionBase::SetValues(const std::vector<const Const*> &vals)
{
	m_left->SetValues(vals);
	m_right->SetValues(vals);
}
//-----------------------------------------------------------------------------------------
Const* BinaryFunctionBase::Compute() const 
{
	m_right->Compute();
}
//-----------------------------------------------------------------------------------------
}


