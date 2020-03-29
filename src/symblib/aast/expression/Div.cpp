#include "Div.h"

#include "symblib/aast/expression/ExpressionType.h"

namespace symb
{
//------------------------------------------------------------------------------
Div::Div(Expression&& left, Expression&& right)
	: Base(ExpressionType::Div, { std::move(left), std::move(right) })
{
}
//------------------------------------------------------------------------------
Div::Div(const Expression& left, const Expression& right)
	: Div(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Div::Div(Arguments&& values)
	: Base(ExpressionType::Div, std::move(values))
{
}
//------------------------------------------------------------------------------
Div::Div()
	: Base(ExpressionType::Div)
{
}
//------------------------------------------------------------------------------
}
