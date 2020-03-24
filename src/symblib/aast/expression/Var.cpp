#include "Var.h"
#include "symblib/aast/expression/ExpressionType.h"

namespace symb
{
//------------------------------------------------------------------------------
void Var::SetLabel(const std::string &label)
{
	m_label = label;
}
//------------------------------------------------------------------------------
std::string Var::GetLabel() const 
{
	return m_label;
}
//------------------------------------------------------------------------------
void Var::SetVal(Real val)
{
	m_value = val;
}
//------------------------------------------------------------------------------
Expression Var::Copy() const
{
	return MakeExpression<Var>(m_label, m_value, m_isVariable);
}
//------------------------------------------------------------------------------
Var::Var(std::string label, Real val, bool isVariable)
	: ExpressionBase(isVariable ? ExpressionType::Var : ExpressionType::Const, val)
	, m_label(std::move(label))
	, m_isVariable(isVariable)
{
}
//------------------------------------------------------------------------------
Var::Var()
	: Var("")
{
}
//------------------------------------------------------------------------------
void Var::SetValues(const std::unordered_map<std::string, Real> &vals)
{
	const auto valueIt = vals.find(m_label);
	if(valueIt == vals.end()) return;

	m_value = valueIt->second;
}
//------------------------------------------------------------------------------
}


