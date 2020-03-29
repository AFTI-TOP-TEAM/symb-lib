#include "Equality.h"

#include "symblib/aast/expression/ExpressionType.h"

namespace symb
{
//------------------------------------------------------------------------------	
Equality::Equality()
	: Base(ExpressionType::Equality)
{
}
//------------------------------------------------------------------------------
Equality::Equality(Expression&& left, Expression&& right)
	: Base(ExpressionType::Equality, { std::move(left), std::move(right) })
{
}
//------------------------------------------------------------------------------
Equality::Equality(const Expression& left, const Expression& rigHt)
	: Equality(left->Copy(), rigHt->Copy())
{
}
//------------------------------------------------------------------------------
Equality::Equality(Arguments&& values)
	: Base(ExpressionType::Equality, std::move(values))
{
}
//------------------------------------------------------------------------------
}
