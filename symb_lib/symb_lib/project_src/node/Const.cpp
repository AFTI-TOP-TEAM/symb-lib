#include "UnaryExpressionBase.h"
#include "project_src/manager/ExpressionManager.h"

namespace symb
{
//------------------------------------------------------------------------------
Const::Const()
	: m_val(0.0)
	, m_isVariable(false)
{
}
//------------------------------------------------------------------------------
Const::Const(Real val)
	: m_val(val)
{
}
//------------------------------------------------------------------------------
IExpression* Const::Derivate() const 
{
	const Real val = m_isVariable ? 1.0 : 0.0;

	auto derivative = FactoryManager::Instance().CreateExpression<Const>(val);
	return derivative; // Const(0) or Pow(0, 0)??
}
//------------------------------------------------------------------------------
IExpression* Const::Integrate() const 
{
	return nullptr; // Pow(x, 1)
}
//------------------------------------------------------------------------------
IExpression* Const::Execute()
{
	return this;
}
//------------------------------------------------------------------------------
void Const::SetLabel(const std::string &label)
{
	m_label = label;
}
//------------------------------------------------------------------------------
std::string Const::GetLabel() const 
{
	return m_label;
}
//------------------------------------------------------------------------------
void Const::SetValues(const std::unordered_map<std::string, Real> &vals)
{
	if(vals.count(m_label) == 0) return;

	m_val = vals[m_label];
}
//------------------------------------------------------------------------------
Real Const::Compute()
{
	return m_val;
}
//------------------------------------------------------------------------------
}


