#pragma once
#include "parser/Grammar.h"
#include <variant>

namespace parse {

class bad_string: public std::exception
{
public:
    bad_string(const std::string& what) noexcept
      :m_what(what)
    {

    }

    const char* what() const noexcept override{
        return m_what.c_str();
    }
private:
    const std::string m_what;
};


template<typename Iterator>
class Parser final{
public:
    Parser(Iterator begin, Iterator end):
        m_begin(begin), m_end(end)
    {

    }

    const ast::program& apply(){
        boost::spirit::ascii::space_type space;
        parse::Grammar<std::string::const_iterator> calc;
        bool ret =  phrase_parse(m_begin, m_end, calc, space, m_program);
        if(ret && (m_end == m_begin)) {
            return m_program;
        }else{
            throw bad_string(std::string(m_begin, m_end));
        }
    }

private:

    ast::program m_program;
    Iterator m_begin, m_end;
};

}
