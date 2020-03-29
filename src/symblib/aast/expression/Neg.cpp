#include "Neg.h"

#include "symblib/aast/expression/ExpressionType.h"

namespace symb
{
//------------------------------------------------------------------------------	
Neg::Neg()
	: Base(ExpressionType::Neg)
{
}
//------------------------------------------------------------------------------
Neg::Neg(Expression&& expr)
    : Base(ExpressionType::Neg, { std::move(expr) })
{
}
//------------------------------------------------------------------------------
Neg::Neg(const Expression& expr)
	: Neg(expr->Copy())
{
}
//------------------------------------------------------------------------------
Neg::Neg(Arguments&& values)
	: Base(ExpressionType::Neg, std::move(values))
{
}
//------------------------------------------------------------------------------
}
