#include "BinaryExpressionBase.h"
#include "Const.h"

namespace symb
{
//-----------------------------------------------------------------------------------------	
BinaryExpressionBase::BinaryExpressionBase(Expression& left, Expression& right)
	: m_left(left.release())
	, m_right(right.release())
{
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetLeftArg(Expression& left)
{
	m_left = std::move(left);
}
//-----------------------------------------------------------------------------------------
const Expression& BinaryExpressionBase::GetLeftArg() const
{
	return m_left;
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetRightArg(Expression& right)
{
	m_right = std::move(right);
}
//-----------------------------------------------------------------------------------------
const Expression& BinaryExpressionBase::GetRightArg() const
{
	return m_right;
}
//-----------------------------------------------------------------------------------------
Expression BinaryExpressionBase::Execute()
{
	m_left = m_left->Execute();
	m_right = m_right->Execute();

	const auto leftConst = dynamic_cast<Const*>(m_left.get());
	const auto rightConst = dynamic_cast<Const*>(m_right.get());

	if (rightConst != nullptr && leftConst != nullptr
		&& rightConst->IsVariable() && leftConst->IsVariable())
	{
		const auto leftRes = leftConst->Compute();
		const auto rightRes = rightConst->Compute();

		const auto result = ComputeImpl(leftRes, rightRes);

		return std::make_unique<Const>("", false, result);
	}
	
	return ExecuteImpl();
}
//-----------------------------------------------------------------------------------------
Expression BinaryExpressionBase::Derivate() const
{
	auto leftDerivative = m_left->Derivate();
	auto rightDerivative = m_right->Derivate();

	return DerivateImpl(leftDerivative, rightDerivative);
}
//-----------------------------------------------------------------------------------------
Expression BinaryExpressionBase::Copy() const
{
	auto left = m_left->Derivate();
	auto right = m_right->Derivate();

	return CopyImpl(left, right);
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetOptimized(bool optimized)
{
	m_isOptimized = optimized;
}
//-----------------------------------------------------------------------------------------
bool BinaryExpressionBase::IsOptimized() const
{
	return m_isOptimized;
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetValues(const std::unordered_map<std::string, Real> &vals)
{
	m_left->SetValues(vals);
	m_right->SetValues(vals);
}
//-----------------------------------------------------------------------------------------
Real BinaryExpressionBase::Compute() const
{
	const auto left = m_left->Compute();
	const auto right = m_right->Compute();

	return ComputeImpl(left, right);
}
//-----------------------------------------------------------------------------------------
}


