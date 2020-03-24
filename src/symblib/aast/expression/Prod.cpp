#include "Prod.h"

#include "symblib/aast/expression/ExpressionType.h"

namespace symb
{
//------------------------------------------------------------------------------
Prod::Prod(Expression&& left, Expression&& right)
	: NthExpression(ExpressionType::Prod, { std::move(left), std::move(right) })
{
}
//------------------------------------------------------------------------------
Prod::Prod(const Expression& left, const Expression& right)
	: Prod(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------	
Prod::Prod(std::vector<Expression>&& values)
	: NthExpression(ExpressionType::Prod, std::move(values))
{
}
//------------------------------------------------------------------------------	
Prod::Prod()
	: NthExpression(ExpressionType::Prod)
{
}
//------------------------------------------------------------------------------	
}
