#pragma once
#include "Iast.h"

namespace ast {

class Walker {
public:
    virtual double operator()(ast::nil) const = 0;

    virtual double operator()(double n) const = 0;

    virtual double operator()(ast::operation const& x, double lhs) const = 0;

    virtual double operator()(ast::signed_ const& x) const = 0;

    virtual double operator()(ast::program const& x) const = 0;

    virtual double operator()(ast::function const& n) const = 0;
};

}
