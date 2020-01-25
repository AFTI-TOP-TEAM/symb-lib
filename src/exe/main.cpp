#include <node/Var.h>
#include <node/Diff.h>
#include <node/Div.h>
#include <node/Sum.h>
#include <node/Prod.h>

#include "manager/ExpressionManager.h"
#include "node/Const.h"

int main()
{
	const auto const1 = symb::MakeExpression<symb::Const>(1);
	const auto const2 = symb::MakeExpression<symb::Const>(2);
	auto const3 = symb::MakeExpression<symb::Const>(3);

	//const3 = const3->Execute();
	
	auto summ1 = symb::MakeExpression<symb::Sum>(const1, const2);

	//summ1 = summ1->Execute();
	
	const auto summ2 = symb::MakeExpression<symb::Sum>(const1, const3);

	const auto x = symb::MakeExpression<symb::Var>("x", 1, true);
	
	const auto prod = symb::MakeExpression<symb::Prod>(summ1, summ2);

	auto div = symb::MakeExpression<symb::Div>(prod, x);
	
	return 0;
}
