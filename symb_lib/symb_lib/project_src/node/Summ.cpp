#include "Summ.h"

#include "Const.h"

namespace symb
{
//------------------------------------------------------------------------------
Summ::Summ(Expression&& left, Expression&& right)
	: BinaryExpressionBase(std::move(left), std::move(right))
{
}
//------------------------------------------------------------------------------
Summ::Summ(const Expression& left, const Expression& right)
	: Summ(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Expression Summ::ExecuteImpl()
{
	return Expression(this);
}
//------------------------------------------------------------------------------
Real Summ::ComputeImpl(Real left, Real right) const
{
	return left + right;
}
//------------------------------------------------------------------------------
Expression Summ::DerivateImpl(Expression&& left, Expression&& right) const
{
	auto result = std::make_unique<Summ>(std::move(left), std::move(right));

	return result->Execute();
}
//------------------------------------------------------------------------------
Expression Summ::CopyImpl(Expression&& left, Expression&& right) const
{
	return std::make_unique<Summ>(std::move(left), std::move(right));
}
//------------------------------------------------------------------------------	
}
