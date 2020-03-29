#include "Prod.h"

#include "symblib/aast/expression/ExpressionType.h"

namespace symb
{
//------------------------------------------------------------------------------
Prod::Prod(Expression&& left, Expression&& right)
	: Base(ExpressionType::Prod, { std::move(left), std::move(right) })
{
}
//------------------------------------------------------------------------------
Prod::Prod(const Expression& left, const Expression& right)
	: Prod(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------	
Prod::Prod(Arguments&& values)
	: Base(ExpressionType::Prod, std::move(values))
{
}
//------------------------------------------------------------------------------	
Prod::Prod()
	: Base(ExpressionType::Prod)
{
}
//------------------------------------------------------------------------------	
}
