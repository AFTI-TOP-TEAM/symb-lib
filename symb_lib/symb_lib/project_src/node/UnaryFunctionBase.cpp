#include "UnaryFunctionBase.h"

namespace symb
{
//------------------------------------------------------------------------------
void UnaryFunctionBase::SetArg(IFunction* arg)
{
	m_arg = arg;
}
//------------------------------------------------------------------------------
IFunction* UnaryFunctionBase::GetArg() const 
{
	return m_arg;
}
//------------------------------------------------------------------------------
IFunction* UnaryFunctionBase::Execute()
{
	return ExecuteImpl(m_arg->Execute());
}
//------------------------------------------------------------------------------
void UnaryFunctionBase::SetValues(const std::vector<const Const*> &vals)
{
	m_arg->SetValues(vals);
}
//------------------------------------------------------------------------------
Const* UnaryFunctionBase::Compute() const 
{
	ComputeImpl(m_arg->Compute());
}
//------------------------------------------------------------------------------
void UnaryFunctionBase::SetLabel(const std::string &label)
{
	m_label = label;
}
//------------------------------------------------------------------------------
std::string UnaryFunctionBase::GetLabel() const
{
	return m_label;
}
//------------------------------------------------------------------------------
}


