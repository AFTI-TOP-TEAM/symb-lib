#include "Neg.h"

namespace symb
{
//------------------------------------------------------------------------------
Neg::Neg(Expression&& expr)
    : UnaryExpressionBase(std::move(expr))
{
}
//------------------------------------------------------------------------------
std::string Neg::GetType() const
{
    return "~";
}
//------------------------------------------------------------------------------
Expression Neg::CopyImpl(Expression&& expression) const
{
    return std::make_unique<Neg>(std::move(expression));
}
//------------------------------------------------------------------------------
Expression Neg::RowExpression() const
{
    return std::unique_ptr<Neg>();
}
}
