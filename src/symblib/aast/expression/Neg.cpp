#include "Neg.h"

#include "symblib/aast/expression/ExpressionType.h"

namespace symb
{
//------------------------------------------------------------------------------	
Neg::Neg()
	: NthExpression(ExpressionType::Neg)
{
}
//------------------------------------------------------------------------------
Neg::Neg(Expression&& expr)
    : NthExpression(ExpressionType::Neg, { std::move(expr) })
{
}
//------------------------------------------------------------------------------
Neg::Neg(const Expression& expr)
	: Neg(expr->Copy())
{
}
//------------------------------------------------------------------------------
Neg::Neg(std::vector<Expression>&& values)
	: NthExpression(ExpressionType::Neg, std::move(values))
{
}
//------------------------------------------------------------------------------
}
