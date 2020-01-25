#include "Equality.h"

namespace symb
{
//------------------------------------------------------------------------------
Equality::Equality(Expression&& left, Expression&& right)
	: BinaryExpressionBase(std::move(left), std::move(right))
{
}
//------------------------------------------------------------------------------
Equality::Equality(const Expression& left, const Expression& rigHt)
	: BinaryExpressionBase(left->Copy(), rigHt->Copy())
{
}
//------------------------------------------------------------------------------
Expression Equality::RowExpression() const
{
	return std::make_unique<Equality>();
}
//------------------------------------------------------------------------------
std::string Equality::GetType() const
{
	return "=";
}
//------------------------------------------------------------------------------
Expression Equality::CopyImpl(Expression&& left, Expression&& right) const
{
	return std::make_unique<Equality>(std::move(left), std::move(right));
}
//------------------------------------------------------------------------------	
}
