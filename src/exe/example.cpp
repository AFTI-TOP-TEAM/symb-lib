#include "symblib/parser/boost_parser/Parser.h"
#include "symblib/parser/boost_parser/Walker.h"

class AstEval : public ast::Walker<double> {
public:
    double operator()(ast::Nil) const override
    {
        BOOST_ASSERT(0);
        return 0;
    }

    double operator()(double n) const override
    {
        return n;
    }

    double operator()(ast::Function const& n) const override
    {
        double rhs = (*this)(n.first_arg);
        if (n.identifier == "log10") {
            return std::log10(rhs);
        } else if (n.identifier == "exp") {
            return std::exp(rhs);
        }
        BOOST_ASSERT(0);
        return 0;
    }

    double operator()(ast::Operation const& x, double lhs) const override
    {
        double rhs = boost::apply_visitor(*this, x.operand_);
        switch (x.operator_) {
        case '+':
            return lhs + rhs;
        case '-':
            return lhs - rhs;
        case '*':
            return lhs * rhs;
        case '/':
            return lhs / rhs;
        case '^':
            return std::pow(lhs, rhs);
        }
        BOOST_ASSERT(0);
        return 0;
    }

    double operator()(ast::Signed const& x) const override
    {
        double rhs = boost::apply_visitor(*this, x.operand_);
        switch (x.sign) {
        case '-':
            return -rhs;
        case '+':
            return +rhs;
        }
        BOOST_ASSERT(0);
        return 0;
    }

    double operator()(ast::Program const& x) const override
    {
        double state = boost::apply_visitor(*this, x.first);
        BOOST_FOREACH (ast::Operation const& oper, x.rest) {
            state = (*this)(oper, state);
        }
        return state;
    }
};

int main()
{
    std::cout << "Enter Ctrl+C for exit" << std::endl;
    std::string str;
    std::cout << "> ";
    AstEval eval;
    while (std::getline(std::cin, str)) {
        std::string::const_iterator begin = str.begin();
        std::string::const_iterator end = str.end();
        parse::Parser parser(begin, end);
        try {
            auto program = parser.apply();
            std::cout << "\nResult: " << eval(program) << std::endl;
        } catch (std::exception& ex) {
            std::cout << "Fail. Stopped at: " << ex.what() << std::endl;
        }
        std::cout << "> ";
    }
    return 0;
}
