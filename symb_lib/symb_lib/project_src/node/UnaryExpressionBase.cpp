#include "UnaryExpressionBase.h"

namespace symb
{
//------------------------------------------------------------------------------	
UnaryExpressionBase::UnaryExpressionBase(Expression& expr)
	: m_arg(expr.release())
{
}
//------------------------------------------------------------------------------
void UnaryExpressionBase::SetArg(Expression& arg)
{
	m_arg = std::move(arg);
}
//------------------------------------------------------------------------------
const Expression& UnaryExpressionBase::GetArg() const
{
	return m_arg;
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
	auto arg = m_arg->Copy();

	return CopyImpl(arg);
}
//------------------------------------------------------------------------------
Expression UnaryExpressionBase::Derivate() const
{
	auto derivative = m_arg->Derivate();

	return DerivateImpl(derivative);
}
//------------------------------------------------------------------------------
void UnaryExpressionBase::SetOptimized(bool optimized)
{
	m_optimized = optimized;
}
//------------------------------------------------------------------------------
bool UnaryExpressionBase::IsOptimized() const
{
	return m_optimized;
}
//------------------------------------------------------------------------------
}


