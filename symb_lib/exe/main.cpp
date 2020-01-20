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
	const auto const3 = symb::MakeExpression<symb::Const>(3);

	const auto summ1 = symb::MakeExpression<symb::Summ>(const1, const2);
	const auto summ2 = symb::MakeExpression<symb::Summ>(const1, const3);

	const auto x = symb::MakeExpression<symb::Const>(1, "x", true);
	
	const auto prod = symb::MakeExpression<symb::Prod>(summ1, summ2);

	auto div = symb::MakeExpression<symb::Div>(prod, x);

	div = div->Execute();

	std::cout << div->Compute();
	
	return 0;
}