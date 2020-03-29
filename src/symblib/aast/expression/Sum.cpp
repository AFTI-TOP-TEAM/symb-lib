#include "Sum.h"

#include "symblib/aast/expression/ExpressionType.h"
#include <array>

namespace symb
{
//------------------------------------------------------------------------------
Sum::Sum(Expression&& left, Expression&& right)
	: Base(ExpressionType::Sum, { std::move(left), std::move(right) })
{
}
//------------------------------------------------------------------------------
Sum::Sum(const Expression& left, const Expression& right)
	: Sum(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Sum::Sum(Arguments&& values)
	: Base(ExpressionType::Sum, std::move(values))
{
}
//------------------------------------------------------------------------------
Sum::Sum()
	: Base(ExpressionType::Sum)
{
}
//------------------------------------------------------------------------------
}
