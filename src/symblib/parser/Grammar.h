//------------------------------------------------------------------------------
// Grammar.h
//
// Grammar descryption. Boost.spirit is applied to create parser.
//
// Copyright (c) 2020 Afti
// All rights reserved.
//
// Date: 25.01.2020
// Author: minium2
//------------------------------------------------------------------------------
#pragma once
#include "parser/Iast.h"

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/foreach.hpp>

namespace parse {

template <typename Iterator>
struct Grammar : boost::spirit::qi::grammar<Iterator, ast::Program(), boost::spirit::ascii::space_type>
{

    Grammar() : Grammar::base_type(expression)
    {
        using boost::spirit::qi::lexeme;
        boost::spirit::qi::double_type double_;
        boost::spirit::qi::char_type char_;

        expression = term >> *((char_('+') >> term)|(char_('-') >> term));

        term = pow >> *((char_('*') >> pow)|(char_('/') >> pow));
        pow = factor >> *(char_('^') >> factor);

        factor = double_|'(' >> expression >> ')'
                |(char_('-') >> factor)
                |(char_('+') >> factor)
                |func;
        func = lexeme[+(char_("[a-zA-Z][a-zA-Z0-9_]*"))]
                >> '(' >> expression >> *(',' >> expression) >> ')';
    }

    boost::spirit::qi::rule<Iterator, ast::Program(), boost::spirit::ascii::space_type> expression;
    boost::spirit::qi::rule<Iterator, ast::Program(), boost::spirit::ascii::space_type> term, pow;
    boost::spirit::qi::rule<Iterator, ast::Operand(), boost::spirit::ascii::space_type> factor;
    boost::spirit::qi::rule<Iterator, ast::Function(), boost::spirit::ascii::space_type> func;

};

}
