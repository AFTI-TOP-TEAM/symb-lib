#include "BinaryExpressionBase.h"
#include "Const.h"

namespace symb
{
//-----------------------------------------------------------------------------------------	
BinaryExpressionBase::BinaryExpressionBase(Expression&& left, Expression&& right)
	: m_left(std::move(left))
	, m_right(std::move(right))
{
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetLeftArg(Expression&& left)
{
	m_left = std::move(left);
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetLeftArg(const Expression& left)
{
	SetLeftArg(left->Copy());
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetRightArg(const Expression& right)
{
	SetRightArg(right->Copy());
}
//-----------------------------------------------------------------------------------------
const Expression& BinaryExpressionBase::GetLeftArg() const
{
	return m_left;
}
//-----------------------------------------------------------------------------------------
Expression&& BinaryExpressionBase::ReleaseLeftArg()
{
	return std::move(m_left);
}
//-----------------------------------------------------------------------------------------
Expression&& BinaryExpressionBase::ReleaseRightArg()
{
	return std::move(m_right);
}
//-----------------------------------------------------------------------------------------
void BinaryExpressionBase::SetRightArg(Expression&& right)
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

		return std::make_unique<Const>(result);
	}
	
	return ExecuteImpl();
}
//-----------------------------------------------------------------------------------------
Expression BinaryExpressionBase::Derivate() const
{
	return DerivateImpl(m_left->Derivate(), m_right->Derivate());
}
//-----------------------------------------------------------------------------------------
Expression BinaryExpressionBase::Copy() const
{
	return CopyImpl(m_left->Copy(), m_right->Copy());
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


