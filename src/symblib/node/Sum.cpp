#include "Sum.h"

namespace symb {
//------------------------------------------------------------------------------
Sum::Sum(Expression&& left, Expression&& right)
    : BinaryExpressionBase(std::move(left), std::move(right))
{
}
//------------------------------------------------------------------------------
Sum::Sum(const Expression& left, const Expression& right)
    : Sum(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Expression Sum::RowExpression() const
{
    return std::unique_ptr<Sum>();
}
//------------------------------------------------------------------------------
std::string Sum::GetType() const
{
    return "+";
}
//------------------------------------------------------------------------------
Expression Sum::CopyImpl(Expression&& left, Expression&& right) const
{
    return std::make_unique<Sum>(std::move(left), std::move(right));
}
//------------------------------------------------------------------------------
}
