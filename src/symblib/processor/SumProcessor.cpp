#include "SumProcessor.h"
#include "../classlib/memory.h"

#include "../node/Sum.h"
#include "../node/Var.h"

#include "ExpressionProcessor.h"

namespace symb
{
REGISTER_PROCESSOR("+", SumProcessor);
//------------------------------------------------------------------------------	
Real SumProcessor::ComputeImpl(Expression&& expr) const
{
	return 0;
}
//------------------------------------------------------------------------------	
Expression SumProcessor::IntegrateImpl(Expression&& expr) const
{
	return Expression();
}
//------------------------------------------------------------------------------	
Expression SumProcessor::DerivateImpl(Expression&& expr) const
{
	return Expression();
}
//------------------------------------------------------------------------------	
Expression SumProcessor::SimplifyImpl(Expression&& expr) const
{
	if (expr->IsOptimized()) return expr->Copy();

	auto sum = dynamic_unique_cast<Sum>(std::move(expr));

	auto &left = sum->GetLeftArg();
	auto &right  = sum->GetRightArg();

	const auto leftConst = dynamic_cast<Var*>(left.get());
	const auto rightConst = dynamic_cast<Var*>(right.get());
	
	if (leftConst != nullptr || rightConst != nullptr)
	{
		//if(leftConst != nullptr && leftConst->Compute() == 0) return sum->ReleaseRightArg();
		//if(rightConst != nullptr && rightConst->Compute() == 0) return sum->ReleaseLeftArg();

		//if (rightConst != nullptr) return std::make_unique<Const>(leftConst->Compute() + rightConst->Compute());

		//so if labels are equal, then isVars are also equal
		if (rightConst != nullptr && 
			leftConst->GetLabel() == rightConst->GetLabel())
		{
			
		}
	}
	
	return Expression(std::move(expr));
}
//------------------------------------------------------------------------------	
}
