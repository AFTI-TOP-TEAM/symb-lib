#include "Diff.h"

namespace symb {
//------------------------------------------------------------------------------
Diff::Diff(Expression&& left, Expression&& right)
    : BinaryExpressionBase(std::move(left), std::move(right))
{
}
//------------------------------------------------------------------------------
Diff::Diff(const Expression& left, const Expression& right)
    : Diff(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Expression Diff::RowExpression() const
{
    return std::unique_ptr<Diff>();
}
//------------------------------------------------------------------------------
std::string Diff::GetType() const
{
    return "-";
}
//------------------------------------------------------------------------------
Expression Diff::CopyImpl(Expression&& left, Expression&& right) const
{
    return std::make_unique<Diff>(std::move(left), std::move(right));
}
//------------------------------------------------------------------------------
}
