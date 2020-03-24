#pragma once
#include <type_traits>

namespace detail
{
	
// To allow ADL with custom begin/end
using std::begin;
using std::end;

template <typename T>
constexpr auto IsIterableImpl(int)
    -> decltype (
        begin(std::declval<T&>()) != end(std::declval<T&>()), // begin/end and operator !=
        void(), // Handle evil operator ,
        ++std::declval<decltype(begin(std::declval<T&>()))&>(), // operator ++
        void(*begin(std::declval<T&>())), // operator*
        std::true_type{});

template <typename T>
std::false_type IsIterableImpl(...);

}

template <typename T>
using IsIterable = decltype(detail::IsIterableImpl<T>(0));