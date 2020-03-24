#include "Diff.h"

#include "symblib/aast/expression/ExpressionType.h"

namespace symb
{
//------------------------------------------------------------------------------	
Diff::Diff(Expression&& left, Expression&& right)
	: NthExpression(ExpressionType::Diff, { std::move(left), std::move(right) })
{
}
//------------------------------------------------------------------------------
Diff::Diff(std::vector<Expression>&& values)
	: NthExpression(ExpressionType::Diff, std::move(values))
{
}
//------------------------------------------------------------------------------
Diff::Diff(const Expression& left, const Expression& right)
	: Diff(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Diff::Diff()
	: NthExpression(ExpressionType::Diff)
{
}
//------------------------------------------------------------------------------
}

