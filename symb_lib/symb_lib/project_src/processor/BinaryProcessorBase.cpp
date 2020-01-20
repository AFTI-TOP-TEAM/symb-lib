#include "../node/BinaryExpressionBase.h"
#include "BinaryProcessorBase.h"
#include "ExpressionProcessor.h"

#include "../classlib/memory.h"
#include "../node/Const.h"

namespace symb
{
//------------------------------------------------------------------------------	
Expression BinaryProcessorBase::Simplify(const Expression& expr) const
{
	const auto binExpr = dynamic_cast<BinaryExpressionBase*>(expr.get());

	if (expr->IsOptimized() || binExpr == nullptr) return expr->Copy();
	const auto& processor = ExpressionProcessor::Instance();
	
	auto &&left = processor.Simplify(binExpr->GetLeftArg());
	auto &&right = processor.Simplify(binExpr->GetRightArg());

	const auto leftConst = dynamic_cast<Const*>(left.get());
	const auto rightConst = dynamic_cast<Const*>(right.get());

	if (leftConst != nullptr && rightConst != nullptr
		&& !leftConst->IsVariable() && !rightConst->IsVariable())
	{
		const auto val = binExpr->ComputeImpl(leftConst->Compute(), rightConst->Compute());

		auto&& res = dynamic_unique_cast<Const>(std::move(left));

		res->SetVal(val);

		return std::move(res);
	}

	auto rowExpr = dynamic_unique_cast<BinaryExpressionBase>(expr->RowExpression());

	rowExpr->SetLeftArg(left);
	rowExpr->SetRightArg(right);

	return SimplifyImpl(std::move(rowExpr));
}
//------------------------------------------------------------------------------	
}
