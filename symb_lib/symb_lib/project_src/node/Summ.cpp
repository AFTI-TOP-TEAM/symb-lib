#include "Summ.h"

#include "Const.h"

namespace symb
{
//------------------------------------------------------------------------------
Summ::Summ(Expression& left, Expression& right)
	: BinaryExpressionBase(left, right)
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
Expression Summ::DerivateImpl(Expression& left, Expression& right) const
{
	auto result = std::make_unique<Summ>(left, right);

	return result->Execute();
}
//------------------------------------------------------------------------------
Expression Summ::CopyImpl(Expression& left, Expression& right) const
{
	return std::make_unique<Summ>(left, right);
}
//------------------------------------------------------------------------------	
}
