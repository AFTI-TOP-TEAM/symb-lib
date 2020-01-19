//------------------------------------------------------------------------------
// FunctionManager.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#include "project_src/node/IFunction.h"

#include <vector>
#include <memory>

namespace symb
{

class FunctionManager final
{
public:

	~FunctionManager() = default; 

	static FunctionManager&	Instance();

	template <typename T, typename... Args> 
	IFunction*	CreateFunction();
private:

	FunctionManager() = default;

	std::vector<std::unique_ptr<IFunction>>		m_functions;
};

template <typename T, typename... Args>
IFunction* symb::FunctionManager::CreateFunction(Args&&... args)
{
	auto rowFunction = new T(std::forward<Args>(args)...);
	if(nullptr != function = dynamic_cast<IFunction>(function))
		m_functions.emplace_back(function);
	
	return rowFunction;
}

}