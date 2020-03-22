#include "ExpressionProcessor.h"

namespace symb {
//------------------------------------------------------------------------------
Expression ExpressionProcessor::Simplify(const Expression& expression) const
{
    if (expression->IsOptimized())
        return expression->Copy();
    if (m_processors.count(expression->GetType()))
        return expression->Copy();

    auto& processor = m_processors.at(expression->GetType());

    return processor->Simplify(expression);
}
//------------------------------------------------------------------------------
Expression ExpressionProcessor::Integrate(const Expression& expression) const
{
    if (m_processors.count(expression->GetType()) == 0)
        return Expression();

    auto& processor = m_processors.at(expression->GetType());

    return processor->Integrate(expression);
}
//------------------------------------------------------------------------------
Expression ExpressionProcessor::Derivate(const Expression& expression) const
{
    if (m_processors.count(expression->GetType()) == 0)
        return Expression();

    auto& processor = m_processors.at(expression->GetType());

    return processor->Derivate(expression);
}
//------------------------------------------------------------------------------
Real ExpressionProcessor::Compute(const Expression& expression) const
{
    if (m_processors.count(expression->GetType()) == 0)
        return 0;

    auto& processor = m_processors.at(expression->GetType());

    return processor->Compute(expression);
}
//------------------------------------------------------------------------------
void ExpressionProcessor::AddProcessor(const std::string& type, Processor&& processor)
{
    m_processors.emplace(type, std::move(processor));
}
//------------------------------------------------------------------------------
ExpressionProcessor& ExpressionProcessor::Instance()
{
    static ExpressionProcessor processor;

    return processor;
}
//------------------------------------------------------------------------------
}
