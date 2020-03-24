#include "Equality.h"

#include "symblib/aast/expression/ExpressionType.h"

namespace symb
{
//------------------------------------------------------------------------------	
Equality::Equality()
	: NthExpression(ExpressionType::Equality)
{
}
//------------------------------------------------------------------------------
Equality::Equality(Expression&& left, Expression&& right)
	: NthExpression(ExpressionType::Equality, { std::move(left), std::move(right) })
{
}
//------------------------------------------------------------------------------
Equality::Equality(const Expression& left, const Expression& rigHt)
	: Equality(left->Copy(), rigHt->Copy())
{
}
//------------------------------------------------------------------------------
Equality::Equality(std::vector<Expression>&& values)
	: NthExpression(ExpressionType::Equality, std::move(values))
{
}
//------------------------------------------------------------------------------
}
