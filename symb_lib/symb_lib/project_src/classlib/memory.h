//------------------------------------------------------------------------------
// memory.h
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 20.01.2020
// Author: Bezborodov Gleb
//------------------------------------------------------------------------------
#pragma once

#include <memory>

namespace symb
{

template <typename To, typename From, typename Deleter>
std::unique_ptr<To, Deleter> dynamic_unique_cast(std::unique_ptr<From, Deleter>&& p)
{
	auto cast = dynamic_cast<To*>(p.get());
	if (cast != nullptr) p.release();

	return std::unique_ptr<To, Deleter>(cast, std::move(p.get_deleter()));
}

template <typename To, typename From>
std::unique_ptr<To> dynamic_unique_cast(std::unique_ptr<From>&& p)
{
	auto cast = dynamic_cast<To*>(p.get());
	if (cast != nullptr) p.release();

	return std::unique_ptr<To>(cast);
}

}
