#include "Div.h"

namespace symb
{
//------------------------------------------------------------------------------
Div::Div(Expression&& left, Expression&& right)
	: BinaryExpressionBase(std::move(left), std::move(right))
{
}
//------------------------------------------------------------------------------
Div::Div(const Expression& left, const Expression& right)
	: Div(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Real Div::ComputeImpl(Real left, Real right) const
{
	if (std::abs(right) < std::numeric_limits<Real>::epsilon()) return std::numeric_limits<Real>::infinity();

	return left / right;
}
//------------------------------------------------------------------------------
Expression Div::ExecuteImpl()
{
	// TODO::add pow...

	return Expression(this);
}
//------------------------------------------------------------------------------
Expression Div::DerivateImpl(Expression&& left, Expression&& right) const
{
	return CopyImpl(std::move(left), std::move(right));
}
//------------------------------------------------------------------------------
Expression Div::CopyImpl(Expression&& left, Expression&& right) const
{
	return std::make_unique<Div>(std::move(left), std::move(right));
}
//------------------------------------------------------------------------------
}
