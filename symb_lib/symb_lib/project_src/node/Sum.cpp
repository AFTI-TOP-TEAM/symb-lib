#include "Sum.h"

#include "Const.h"

namespace symb
{
//------------------------------------------------------------------------------
Sum::Sum(Expression&& left, Expression&& right)
	: BinaryExpressionBase(std::move(left), std::move(right))
{
}
//------------------------------------------------------------------------------
Sum::Sum(const Expression& left, const Expression& right)
	: Sum(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Expression Sum::RowExpression() const
{
	return std::unique_ptr<Sum>();
}
//------------------------------------------------------------------------------
Expression Sum::ExecuteImpl()
{
	return Copy();
}
//------------------------------------------------------------------------------
Real Sum::ComputeImpl(Real left, Real right) const
{
	return left + right;
}
//------------------------------------------------------------------------------
Expression Sum::DerivateImpl(Expression&& left, Expression&& right) const
{
	auto result = std::make_unique<Sum>(std::move(left), std::move(right));

	return result->Execute();
}
//------------------------------------------------------------------------------
Expression Sum::CopyImpl(Expression&& left, Expression&& right) const
{
	return std::make_unique<Sum>(std::move(left), std::move(right));
}
//------------------------------------------------------------------------------	
}
