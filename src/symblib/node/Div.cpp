#include "Div.h"

namespace symb {
//------------------------------------------------------------------------------
Div::Div(Expression&& left, Expression&& right)
    : BinaryExpressionBase(std::move(left), std::move(right))
{
}
//------------------------------------------------------------------------------
Div::Div(const Expression& left, const Expression& right)
    : Div(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Expression Div::RowExpression() const
{
    return std::unique_ptr<Div>();
}
//------------------------------------------------------------------------------
std::string Div::GetType() const
{
    return "/";
}
//------------------------------------------------------------------------------
Expression Div::CopyImpl(Expression&& left, Expression&& right) const
{
    return std::make_unique<Div>(std::move(left), std::move(right));
}
//------------------------------------------------------------------------------
}
