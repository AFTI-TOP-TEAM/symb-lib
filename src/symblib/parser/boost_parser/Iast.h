//------------------------------------------------------------------------------
// Grammar.h
//
// Intermediate ast nodes for grammar descryption.
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 25.01.2020
// Author: minium2
//------------------------------------------------------------------------------
#pragma once

#pragma once
#include <boost/config/warning_disable.hpp>
#include <boost/foreach.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <boost/variant/recursive_variant.hpp>

namespace ast {
struct Nil {
};
struct Signed;
struct Program;
struct Function;

using Operand = boost::variant<
    Nil,
    double,
    boost::recursive_wrapper<Signed>,
    boost::recursive_wrapper<Program>,
    boost::recursive_wrapper<Function>>;

struct Signed {
    char sign;
    Operand operand_;
};

struct Operation {
    char operator_;
    Operand operand_;
};

struct Program {
    Operand first;
    std::list<Operation> rest;
};

struct Function {
    std::string identifier;
    Program first_arg;
    std::list<Program> args;
};
}

BOOST_FUSION_ADAPT_STRUCT(
    ast::Signed,
    (char, sign)(ast::Operand, operand_))

BOOST_FUSION_ADAPT_STRUCT(
    ast::Operation,
    (char, operator_)(ast::Operand, operand_))

BOOST_FUSION_ADAPT_STRUCT(
    ast::Program,
    (ast::Operand, first)(std::list<ast::Operation>, rest))

BOOST_FUSION_ADAPT_STRUCT(
    ast::Function,
    (std::string, identifier)(ast::Program, first_arg)(std::list<ast::Program>, args))
