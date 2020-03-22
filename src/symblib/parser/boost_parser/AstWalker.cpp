#include "AstWalker.h"

#include "node/Const.h"
#include <node/Diff.h>
#include <node/Div.h>
#include <node/Neg.h>
#include <node/Prod.h>
#include <node/Sum.h>
#include <node/Var.h>

namespace ast {
//------------------------------------------------------------------------------
symb::Expression AstWalker::operator()(ast::Nil) const
{
    BOOST_ASSERT(0);
}
//------------------------------------------------------------------------------
symb::Expression AstWalker::operator()(double n) const
{
    return symb::MakeExpression<symb::Const>(n);
}
//------------------------------------------------------------------------------
symb::Expression AstWalker::operator()(ast::Operation const& x, symb::Expression lhs) const
{
    const auto rhs = boost::apply_visitor(*this, x.operand_);
    switch (x.operator_) {
    case '+':
        return symb::MakeExpression<symb::Sum>(std::move(lhs), std::move(rhs));
    case '-':
        return symb::MakeExpression<symb::Diff>(std::move(lhs), std::move(rhs));
    case '*':
        return symb::MakeExpression<symb::Prod>(std::move(lhs), std::move(rhs));
    case '/':
        return symb::MakeExpression<symb::Div>(std::move(lhs), std::move(rhs));
    case '^':
        std::cerr << "pow operation is undefined. Terminated" << std::endl;
    }
    BOOST_ASSERT(0);
}
//------------------------------------------------------------------------------
symb::Expression AstWalker::operator()(ast::Signed const& x) const
{
    symb::Expression rhs = boost::apply_visitor(*this, x.operand_);
    switch (x.sign) {
    case '-':
        return symb::MakeExpression<symb::Neg>(std::move(rhs));
    case '+':
        return std::move(rhs);
    }
    BOOST_ASSERT(0);
    return 0;
}
//------------------------------------------------------------------------------
symb::Expression AstWalker::operator()(ast::Program const& x) const
{
    symb::Expression state = boost::apply_visitor(*this, x.first);
    BOOST_FOREACH (ast::Operation const& oper, x.rest) {
        state = (*this)(oper, std::move(state));
    }
    return std::move(state);
}
//------------------------------------------------------------------------------
symb::Expression AstWalker::operator()(ast::Function const& n) const
{
    BOOST_ASSERT(0);
}
//------------------------------------------------------------------------------
}
