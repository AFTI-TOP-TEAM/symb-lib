#include "Diff.h"

#include "symblib/aast/expression/ExpressionType.h"

namespace symb
{
//------------------------------------------------------------------------------	
Diff::Diff(Expression&& left, Expression&& right)
	: Base(ExpressionType::Diff, { std::move(left), std::move(right) })
{
}
//------------------------------------------------------------------------------
Diff::Diff(Arguments&& values)
	: Base(ExpressionType::Diff, std::move(values))
{
}
//------------------------------------------------------------------------------
Diff::Diff(const Expression& left, const Expression& right)
	: Diff(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Diff::Diff()
	: Base(ExpressionType::Diff)
{
}
//------------------------------------------------------------------------------
}

