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
void UnaryFunctionBase::SetValues(const std::unordered_map<std::string, Real> &vals)
{
	m_arg->SetValues(vals);
}
//------------------------------------------------------------------------------
Real UnaryFunctionBase::Compute() const 
{
	return ComputeImpl(m_arg->Compute());
}
//------------------------------------------------------------------------------
}


