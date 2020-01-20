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
#include <typeinfo>

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
	
	Expression	Simplify(const Expression& expression) const;
	Expression	Integrate(const Expression& expression) const;
	Expression	Derivate(const Expression& expression) const;

	void		AddProcessor(Processor&& processor);

private:
	ExpressionProcessor() = default;

	std::unordered_map<size_t, Processor>	m_processors;
};

template <typename T>
struct ProcessorRegister
{
	ProcessorRegister()
	{
		// МНЕ ЧИСТО ПОХУЙ // MNE CHISTO POHUI //SOSAT SUCHKA
		Processor processor(reinterpret_cast<IProcessorInner*>(new T));
		
		ExpressionProcessor::Instance().AddProcessor(std::move(processor));
	}
};

#define REGISTER_PROCESSOR(processorName) static ProcessorRegister<processorName> registernewRegister##processorName
	
}
