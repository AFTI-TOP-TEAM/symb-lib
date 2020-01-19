#include "Div.h"

namespace symb
{
//------------------------------------------------------------------------------
Div::Div(Expression& left, Expression& right)
	: BinaryExpressionBase(left, right)
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
Expression Div::DerivateImpl(Expression& left, Expression& right) const
{
	return CopyImpl(left, right);
}
//------------------------------------------------------------------------------
Expression Div::CopyImpl(Expression& left, Expression& right) const
{
	return std::make_unique<Div>(left, right);
}
//------------------------------------------------------------------------------
}
