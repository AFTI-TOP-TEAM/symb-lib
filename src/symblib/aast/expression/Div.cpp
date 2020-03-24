#include "Div.h"

#include "symblib/aast/expression/ExpressionType.h"

namespace symb
{
//------------------------------------------------------------------------------
Div::Div(Expression&& left, Expression&& right)
	: NthExpression(ExpressionType::Div, { std::move(left), std::move(right) })
{
}
//------------------------------------------------------------------------------
Div::Div(const Expression& left, const Expression& right)
	: Div(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Div::Div(std::vector<Expression>&& values)
	: NthExpression(ExpressionType::Div, std::move(values))
{
}
//------------------------------------------------------------------------------
Div::Div()
	: NthExpression(ExpressionType::Div)
{
}
//------------------------------------------------------------------------------
}
