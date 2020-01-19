#include "UnaryExpressionBase.h"


namespace symb
{
//------------------------------------------------------------------------------
ExpressionManager& ExpressionManager::Instance()
{
	static ExpressionManager instance;

	return instance;
}
//------------------------------------------------------------------------------
}


