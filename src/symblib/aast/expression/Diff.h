//------------------------------------------------------------------------------
// Diff.h
//
// Diff implements...
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 1.20.2020
// Author: Bezborodov Gleb
//------------------------------------------------------------------------------
#pragma once

#include "NthExpression.h"

namespace symb
{

class Diff final : public NthExpression<Diff, 2>
{
	using Base = NthExpression<Diff, 2>;
public:
	explicit Diff(Expression&& left, Expression&& right);
	explicit Diff(Arguments&& values);
	explicit Diff(const Expression& left, const Expression& right);
	Diff();

	Diff(const Diff&) = delete;
	Diff(Diff&&) = delete;

	Diff operator=(Diff&&) = delete;
	Diff operator=(const Diff&) = delete;
		
	virtual ~Diff() = default;
};

}
