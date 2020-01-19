#include "Prod.h"
#include "Const.h"
#include "Summ.h"

namespace symb
{
//------------------------------------------------------------------------------
Prod::Prod(Expression& left, Expression& right)
	:BinaryExpressionBase(left, right)
{
}
//------------------------------------------------------------------------------
Real Prod::ComputeImpl(Real left, Real right) const
{
	return left * right;
}
//------------------------------------------------------------------------------
Expression Prod::ExecuteImpl()
{
	return Expression(nullptr);
}
//------------------------------------------------------------------------------
Expression Prod::DerivateImpl(Expression& left, Expression& right) const
{
	auto leftProd = std::make_unique<Prod>(left, GetRightArg()->Copy());
	auto rightProd = std::make_unique<Prod>(GetLeftArg()->Copy(), right);

	auto leftE = Expression(leftProd.release());
	auto rightE = Expression(rightProd.release());
	
	auto derivative = std::make_unique<Summ>(leftE, rightE);

	return derivative->Execute();
}
//------------------------------------------------------------------------------
Expression Prod::CopyImpl(Expression& left, Expression& right) const
{
	return std::make_unique<Prod>(left, right);
}
//------------------------------------------------------------------------------	
}
