#include "UnaryExpressionBase.h"

namespace symb
{
//------------------------------------------------------------------------------
void UnaryExpressionBase::SetArg(IExpression* arg)
{
	m_arg = arg;
}
//------------------------------------------------------------------------------
IExpression* UnaryExpressionBase::GetArg() const 
{
	return m_arg;
}
//------------------------------------------------------------------------------
IExpression* UnaryExpressionBase::Execute()
{
	return ExecuteImpl(m_arg->Execute());
}
//------------------------------------------------------------------------------
void UnaryExpressionBase::SetValues(const std::unordered_map<std::string, Real> &vals)
{
	m_arg->SetValues(vals);
}
//------------------------------------------------------------------------------
Real UnaryExpressionBase::Compute() const 
{
	return ComputeImpl(m_arg->Compute());
}
//------------------------------------------------------------------------------
}


