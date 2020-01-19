#include "Const.h"

namespace symb
{
//------------------------------------------------------------------------------
Const::Const()
	: m_val(0.0)
	, m_isVariable(false)
{
}
//------------------------------------------------------------------------------
Const::Const(const std::string& label, bool isVariable, Real val)
	: m_val(val)
	, m_label(label)
	, m_isVariable(isVariable)
{
}
//------------------------------------------------------------------------------
Expression Const::Derivate() const
{
	if (m_isVariable == false) return std::make_unique<Const>("", false,  0);

	return std::make_unique<Const>("", false, 1);
}
//------------------------------------------------------------------------------
Expression Const::Execute()
{
	return Expression(this);
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

	m_val = vals.at(m_label);
}
//------------------------------------------------------------------------------
Real Const::Compute() const
{
	return m_val;
}
//------------------------------------------------------------------------------
bool Const::IsVariable() const
{
	return m_isVariable;
}
//------------------------------------------------------------------------------
Expression Const::Copy() const
{
	return std::make_unique<Const>(m_label, m_isVariable, m_val);
}
//------------------------------------------------------------------------------
}


