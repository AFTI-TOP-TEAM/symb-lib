#pragma once

#pragma once
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/foreach.hpp>

namespace ast {
    struct nil {};
    struct signed_;
    struct program;
    struct function;

    using operand = boost::variant<
        nil,
        double,
        boost::recursive_wrapper<signed_>,
        boost::recursive_wrapper<program>,
        boost::recursive_wrapper<function>
    >;

    struct signed_ {
        char sign;
        operand operand_;
    };

    struct operation {
        char operator_;
        operand operand_;
    };

    struct program {
        operand first;
        std::list<operation> rest;
    };

    struct function {
        std::string identifier;
        program first_arg;
        std::list<program> args;
    };
}

BOOST_FUSION_ADAPT_STRUCT(
    ast::signed_,
    (char, sign)
    (ast::operand, operand_)
)

BOOST_FUSION_ADAPT_STRUCT(
    ast::operation,
    (char, operator_)
    (ast::operand, operand_)
)

BOOST_FUSION_ADAPT_STRUCT(
    ast::program,
    (ast::operand, first)
    (std::list<ast::operation>, rest)
)

BOOST_FUSION_ADAPT_STRUCT(
    ast::function,
    (std::string, identifier)
    (ast::program, first_arg)
    (std::list<ast::program>, args)
)


