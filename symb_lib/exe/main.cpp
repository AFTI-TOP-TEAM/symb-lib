#include <node/Const.h>
#include <node/Diff.h>
#include <node/Div.h>
#include <node/Summ.h>
#include <node/Prod.h>

#include "manager/FunctionManager.h"

#include <iostream>

int main()
{
	const auto const1 = symb::MakeExpression<symb::Const>(1);
	const auto const2 = symb::MakeExpression<symb::Const>(2);
	auto const3 = symb::MakeExpression<symb::Const>(3);

	const3 = const3->Execute();
	
	auto summ1 = symb::MakeExpression<symb::Summ>(const1, const2);

	summ1 = summ1->Execute();
	
	const auto summ2 = symb::MakeExpression<symb::Summ>(const1, const3);

	const auto x = symb::MakeExpression<symb::Const>(1, "x", true);
	
	const auto prod = symb::MakeExpression<symb::Prod>(summ1, summ2);

	auto div = symb::MakeExpression<symb::Div>(prod, x);

	div = div->Execute();

	std::cout << div->Compute();
	
	return 0;
}