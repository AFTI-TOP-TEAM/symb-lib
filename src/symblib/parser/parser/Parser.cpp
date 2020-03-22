#include "Parser.h"
#include "symblib/Nodes.h"
#include "symblib/manager/ExpressionManager.h"
#include "symblib/parser/Location.h"
#include "symblib/parser/lexer/Lexer.h"

namespace parser {

namespace {
    symb::Expression E(Lexer& lex);
    symb::Expression T(Lexer& lex);
    symb::Expression F(Lexer& lex);

    symb::Expression E(Lexer& lex)
    {
        auto lth = T(lex);
        for (auto tok = lex.token(); tok.m_tokenKind != TokenKind::NONE; tok = lex.token()) {
            if (tok.m_tokenKind == TokenKind::PLUS) {
	            // ReSharper disable once CppNoDiscardExpression
	            lex.nextToken();
                auto rth = T(lex);
                lth = symb::MakeExpression<symb::Sum>(std::move(rth), std::move(lth));
            } else if (tok.m_tokenKind == TokenKind::MINUS) {
	            // ReSharper disable once CppNoDiscardExpression
	            lex.nextToken();
                auto rth = T(lex);
                lth = symb::MakeExpression<symb::Div>(std::move(rth), std::move(lth));
            } else {
                throw Location(lex.getStore(), lex.position());
            }
        }
        return lth;
    }

    symb::Expression T(Lexer& lex)
    {
        auto lth = F(lex);
        for (auto tok = lex.token(); tok.m_tokenKind != TokenKind::NONE; tok = lex.token()) {
            if (tok.m_tokenKind == TokenKind::MULT) {
	            // ReSharper disable once CppNoDiscardExpression
	            lex.nextToken();
                auto rth = F(lex);
                lth = symb::MakeExpression<symb::Prod>(std::move(rth), std::move(lth));
            } else if (tok.m_tokenKind == TokenKind::DIV) {
	            // ReSharper disable once CppNoDiscardExpression
	            lex.nextToken();
                auto rth = F(lex);
                lth = symb::MakeExpression<symb::Div>(std::move(rth), std::move(lth));
            } else {
                break;
            }
        }
        return lth;
    }

    symb::Expression F(Lexer& lex)
    {
	    const auto token = lex.token();
        if (token.m_tokenKind == TokenKind::NUMBER) {
	        // ReSharper disable once CppNoDiscardExpression
	        lex.nextToken();
            return symb::MakeExpression<symb::Const>(atof(token.m_str.c_str()));  // NOLINT(cert-err34-c)
        }
	    if (token.m_tokenKind == TokenKind::LEFT_BRACKET) {
		    // ReSharper disable once CppNoDiscardExpression
		    lex.nextToken();
		    auto exp = E(lex);
		    const auto tokenK = lex.nextToken();
		    if (tokenK.m_tokenKind != TokenKind::RIGHT_BRACKET) {
			    throw Location(lex.getStore(), lex.position());
		    }
		    return std::move(exp);
	    }
	    throw Location(lex.getStore(), lex.position());
    }
}

///
/// \brief RecursiveParser::parse
/// Grammar descruption
/// E -> T *("+"T | "-"T)
/// T -> F *("*"F | "-"F)
/// F -> double | "(" E ")"
void RecursiveParser::parse(Lexer& lex)
{
    m_exp = E(lex);
}
}
