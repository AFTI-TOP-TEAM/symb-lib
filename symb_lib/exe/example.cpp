#include "parser/Parser.h"
#include "parser/Walker.h"

class AstEval: public  ast::Walker {
public:
    double operator()(ast::nil) const override
    {
        BOOST_ASSERT(0);
        return 0;
    }

    double operator()(double n) const override
    {
        return n;
    }

    double operator()(ast::function const& n) const override {
        double rhs = (*this)(n.first_arg);
        if(n.identifier == "log10") {
            return std::log10(rhs);
        } else if(n.identifier =="exp"){
            return std::exp(rhs);
        }
        BOOST_ASSERT(0);
        return 0;
    }

    double operator()(ast::operation const& x, double lhs) const override
    {
        int rhs = boost::apply_visitor(*this, x.operand_);
        switch (x.operator_)
        {
            case '+': return lhs + rhs;
            case '-': return lhs - rhs;
            case '*': return lhs * rhs;
            case '/': return lhs / rhs;
            case '^': return std::pow(lhs,  rhs);
        }
        BOOST_ASSERT(0);
        return 0;
    }

    double operator()(ast::signed_ const& x) const override
    {
        double rhs = boost::apply_visitor(*this, x.operand_);
        switch (x.sign)
        {
            case '-':
                return -rhs;
            case '+':
                return +rhs;
        }
        BOOST_ASSERT(0);
        return 0;
    }

    double operator()(ast::program const& x) const override
    {
        double state = boost::apply_visitor(*this, x.first);
        BOOST_FOREACH(ast::operation const& oper, x.rest) {
            state = (*this)(oper, state);
        }
        return state;
    }
};

int main() {
    std::cout<<"Enter Ctrl+C for exit"<<std::endl;
    std::string str;
    std::cout<<"> ";
    AstEval eval;
    while (std::getline(std::cin, str)){
        std::string::const_iterator begin = str.begin();
        std::string::const_iterator end = str.end();
        parse::Parser parser(begin, end);
        try{
            auto program = parser.apply();
            std::cout << "\nResult: " << eval(program) << std::endl;
        }catch(std::exception& ex){
            std::cout<<"Fail. Stopped at: "<<ex.what()<<std::endl;
        }
        std::cout<<"> ";
    }
    return 0;
}
