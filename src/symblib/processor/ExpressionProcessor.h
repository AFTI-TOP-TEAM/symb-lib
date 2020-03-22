//------------------------------------------------------------------------------
// ExpressionProcessor.h
//
// ExpressionProcessor implements...
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 20.01.2020
// Author: Bezborodov Gleb
//------------------------------------------------------------------------------
#pragma once

#include "../node/IExpression.h"
#include <unordered_map>

#include "IProcessorInner.h"

namespace symb
{

class ExpressionProcessor final
{
public:
	ExpressionProcessor(const ExpressionProcessor&) = delete;
	ExpressionProcessor(ExpressionProcessor&&) = delete;

	ExpressionProcessor operator=(const ExpressionProcessor&) = delete;
	ExpressionProcessor operator=(ExpressionProcessor&&) = delete;

	~ExpressionProcessor() = default;

	static	ExpressionProcessor& Instance();

	[[nodiscard]] Expression	Simplify(const Expression& expression) const;

	[[nodiscard]] Expression	Integrate(const Expression& expression) const;

	[[nodiscard]] Expression	Derivate(const Expression& expression) const;

	[[nodiscard]] Real			Compute(const Expression& expression) const;

	void		AddProcessor(const std::string& type, Processor&& processor);

private:
	ExpressionProcessor() = default;

	std::unordered_map<std::string, Processor>	m_processors;
};

template <typename T>
struct ProcessorRegister
{
	explicit constexpr ProcessorRegister(const std::string& type)
	{
		Processor processor(reinterpret_cast<IProcessorInner*>(new T));
		
		ExpressionProcessor::Instance().AddProcessor(type, std::move(processor));
	}
};

#define REGISTER_PROCESSOR(type, processorName) static ProcessorRegister<processorName> registernewRegister##processorName(type)
	
}
