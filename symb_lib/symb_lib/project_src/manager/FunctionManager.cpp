#include "UnaryFunctionBase.h"


namespace symb
{
//------------------------------------------------------------------------------
FunctionManager& FunctionManager::Instance()
{
	static FunctionManager instance;

	return instance;
}
//------------------------------------------------------------------------------
}


