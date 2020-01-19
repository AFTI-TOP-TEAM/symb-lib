#include "Diff.h"

namespace symb
{
//------------------------------------------------------------------------------	
Diff::Diff(Expression& left, Expression& right)
	:BinaryExpressionBase(left, right)
{
}
//------------------------------------------------------------------------------
Real Diff::ComputeImpl(Real left, Real right) const
{
	return left - right;
}
//------------------------------------------------------------------------------
Expression Diff::ExecuteImpl()
{
	return Expression(this);
}
//------------------------------------------------------------------------------
Expression Diff::DerivateImpl(Expression& left, Expression& right) const
{
	auto derivative = std::make_unique<Diff>(left, right);

	return derivative->Execute();
}
//------------------------------------------------------------------------------
Expression Diff::CopyImpl(Expression& left, Expression& right) const
{
	return std::make_unique<Diff>(left, right);
}
//------------------------------------------------------------------------------
}

