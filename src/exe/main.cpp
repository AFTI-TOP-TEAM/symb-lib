#include "../symblib/node/Sum.h"
#include "../symblib/node/Var.h"
#include "../symblib/node/Prod.h"
#include "../symblib/node/Div.h"
#include "../symblib/node/Const.h"
#include "../symblib/manager/ExpressionManager.h"

#include "../symblib/node/AST.h"
#include <iostream>

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

	symb::AST ast(std::move(div));

	for (const auto& e : ast)
		std::cout << e->GetType();

	return 0;
}
