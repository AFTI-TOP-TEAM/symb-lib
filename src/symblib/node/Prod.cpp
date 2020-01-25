#include "Prod.h"

namespace symb
{
//------------------------------------------------------------------------------
Prod::Prod(Expression&& left, Expression&& right)
	:BinaryExpressionBase(std::move(left), std::move(right))
{
}
//------------------------------------------------------------------------------
Prod::Prod(const Expression& left, const Expression& right)
	: Prod(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Expression Prod::RowExpression() const
{
	return std::unique_ptr<Prod>();
}
//------------------------------------------------------------------------------
std::string Prod::GetType() const
{
	return "*";
}
//------------------------------------------------------------------------------
Expression Prod::CopyImpl(Expression&& left, Expression&& right) const
{
	return std::make_unique<Prod>(std::move(left), std::move(right));
}
//------------------------------------------------------------------------------	
}
