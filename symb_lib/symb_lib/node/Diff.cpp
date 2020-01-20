#include "Diff.h"

namespace symb
{
//------------------------------------------------------------------------------	
Diff::Diff(Expression&& left, Expression&& right)
	:BinaryExpressionBase(std::move(left), std::move(right))
{
}
//------------------------------------------------------------------------------
Diff::Diff(const Expression& left, const Expression& right)
	: Diff(left->Copy(), right->Copy())
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
	return Copy();
}
//------------------------------------------------------------------------------
Expression Diff::DerivateImpl(Expression&& left, Expression&& right) const
{
	auto derivative = std::make_unique<Diff>(std::move(left), std::move(right));

	return derivative->Execute();
}
//------------------------------------------------------------------------------
Expression Diff::CopyImpl(Expression&& left, Expression&& right) const
{
	return std::make_unique<Diff>(std::move(left), std::move(right));
}
//------------------------------------------------------------------------------
}

