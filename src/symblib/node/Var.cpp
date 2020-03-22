#include "Var.h"

namespace symb {
//------------------------------------------------------------------------------
Var::Var(const std::string& label, Real val, bool isVariable)
    : m_val(val)
    , m_label(label)
    , m_isVariable(isVariable)
{
}
//------------------------------------------------------------------------------
void Var::SetLabel(const std::string& label)
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
    m_val = val;
}
//------------------------------------------------------------------------------
void Var::SetValues(const std::unordered_map<std::string, Real>& vals)
{
    if (vals.count(m_label) == 0)
        return;

    m_val = vals.at(m_label);
}
//------------------------------------------------------------------------------
bool Var::IsVariable() const
{
    return m_isVariable;
}
//------------------------------------------------------------------------------
std::string Var::GetType() const
{
    return "var";
}
//------------------------------------------------------------------------------
Expression Var::Copy() const
{
    return std::make_unique<Var>(m_label, m_val, m_isVariable);
}
//------------------------------------------------------------------------------
Expression Var::RowExpression() const
{
    return std::unique_ptr<Var>();
}
//------------------------------------------------------------------------------
bool Var::IsOptimized() const
{
    return true;
}
//------------------------------------------------------------------------------
void Var::SetOptimized(bool optimized)
{
    //ignore...
}
//------------------------------------------------------------------------------
}
