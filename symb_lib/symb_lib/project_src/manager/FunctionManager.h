//------------------------------------------------------------------------------
// ExpressionManager.h
// 
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date:       19.01.20
// Author:     glensand
//------------------------------------------------------------------------------

#include "project_src/node/IExpression.h"

#include <vector>
#include <memory>

namespace symb
{

class ExpressionManager final
{
public:

	~ExpressionManager() = default; 

	static ExpressionManager&	Instance();

	template <typename T, typename... Args> 
	IExpression*	CreateExpression();
private:

	ExpressionManager() = default;

	std::vector<std::unique_ptr<IExpression>>		m_expressions;
};

template <typename T, typename... Args>
IExpression* symb::ExpressionManager::CreateExpression(Args&&... args)
{
	auto rowExpression = new T(std::forward<Args>(args)...);
	if(nullptr != expression = dynamic_cast<IExpression>(expression))
		m_expressions.emplace_back(expression);
	
	return rowExpression;
}

}