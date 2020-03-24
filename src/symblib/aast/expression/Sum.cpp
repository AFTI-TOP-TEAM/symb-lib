#include "Sum.h"

#include "symblib/aast/expression/ExpressionType.h"

namespace symb
{
//------------------------------------------------------------------------------
Sum::Sum(Expression&& left, Expression&& right)
	: NthExpression(ExpressionType::Sum, std::vector{ std::move(left), std::move(right) })
{
}
//------------------------------------------------------------------------------
Sum::Sum(const Expression& left, const Expression& right)
	: Sum(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Sum::Sum(std::vector<Expression>&& values)
	: NthExpression(ExpressionType::Sum, std::move(values))
{
}
//------------------------------------------------------------------------------
Sum::Sum()
	: NthExpression(ExpressionType::Sum)
{
}
//------------------------------------------------------------------------------
}
