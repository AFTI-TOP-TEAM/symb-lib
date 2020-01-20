#include "ExpressionProcessor.h"

#include <typeinfo>

namespace symb
{
//------------------------------------------------------------------------------	
Expression ExpressionProcessor::Simplify(const Expression& expression) const
{
	if (expression->IsOptimized()) return expression->Copy();
	
	const auto& typeInfo = typeid(expression.get());
	const auto hashCode = typeInfo.hash_code();

	const auto procIt = m_processors.find(hashCode);

	if (procIt == m_processors.end())
		return expression->Copy();

	return procIt->second->Simplify(expression);
}
//------------------------------------------------------------------------------
Expression ExpressionProcessor::Integrate(const Expression& expression) const
{
	return expression->Copy();
}
//------------------------------------------------------------------------------
Expression ExpressionProcessor::Derivate(const Expression& expression) const
{
	return expression->Derivate();
}
//------------------------------------------------------------------------------
void ExpressionProcessor::AddProcessor(Processor&& processor)
{
	const auto& typeInfo = typeid(processor.get());
	const auto typeHash = typeInfo.hash_code();

	m_processors[typeHash] = std::move(processor);
}
//------------------------------------------------------------------------------
ExpressionProcessor& ExpressionProcessor::Instance()
{
	static ExpressionProcessor processor;

	return processor;
}
//------------------------------------------------------------------------------	
}
