#include "UnaryExpressionBase.h"

namespace symb
{
//------------------------------------------------------------------------------	
UnaryExpressionBase::UnaryExpressionBase(Expression&& expr)
	: m_arg(std::move(expr))
{
}
//------------------------------------------------------------------------------
void UnaryExpressionBase::SetArg(Expression&& arg)
{
	m_arg = std::move(arg);
}
//------------------------------------------------------------------------------
void UnaryExpressionBase::SetArg(const Expression& arg)
{
	SetArg(arg->Copy());
}
//------------------------------------------------------------------------------
const Expression& UnaryExpressionBase::GetArg() const
{
	return m_arg;
}
//------------------------------------------------------------------------------
Expression&& UnaryExpressionBase::ReleaseArg()
{
	return std::move(m_arg);
}
//------------------------------------------------------------------------------
Expression UnaryExpressionBase::Execute()
{
	m_arg = m_arg->Execute();
	
	return ExecuteImpl();
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
Expression UnaryExpressionBase::Copy() const
{
	return CopyImpl(m_arg->Copy());
}
//------------------------------------------------------------------------------
Expression UnaryExpressionBase::Derivate() const
{
	return DerivateImpl(m_arg->Derivate());
}
//------------------------------------------------------------------------------
}