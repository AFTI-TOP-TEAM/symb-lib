#include "SumProcessor.h"
#include "../classlib/memory.h"

#include "../node/Sum.h"
#include "../node/Const.h"

#include "ExpressionProcessor.h"

namespace symb
{
REGISTER_PROCESSOR(SumProcessor);
//------------------------------------------------------------------------------	
Expression SumProcessor::SimplifyImpl(Expression&& expr) const
{
	if (expr->IsOptimized()) return expr->Copy();

	auto sum = dynamic_unique_cast<Sum>(std::move(expr));

	auto &left = sum->GetLeftArg();
	auto &right  = sum->GetRightArg();

	const auto leftConst = dynamic_cast<Const*>(left.get());
	const auto rightConst = dynamic_cast<Const*>(right.get());
	
	if (leftConst != nullptr || rightConst != nullptr)
	{
		if(leftConst != nullptr && leftConst->Compute() == 0) return sum->ReleaseRightArg();
		if(rightConst != nullptr && rightConst->Compute() == 0) return sum->ReleaseLeftArg();

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
