#include "parser/Grammar.h"
namespace parse {

bool parse(std::string& str, ast::program&  program) {
    using iterator_type = std::string::const_iterator;
    using Grammar = parse::Grammar<iterator_type>;
    boost::spirit::ascii::space_type space;
    Grammar calc;
    std::string::const_iterator begin = str.begin();
    std::string::const_iterator end = str.end();
    bool ret = phrase_parse(begin, end, calc, space, program);
    return ret && end == begin;
}

}
