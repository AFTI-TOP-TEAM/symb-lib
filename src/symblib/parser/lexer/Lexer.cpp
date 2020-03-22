#include "symblib/parser/lexer/Lexer.h"
#include <cstdlib>
#include <iostream>
#include <regex>

namespace {
inline void removeDelimiters(const std::string& input, size_t& pos)
{
    while (input[pos] == ' ' || input[pos] == '\t' || input[pos] == '\n') {
        if (input[pos] != '\0') {
            pos += 1;
        }
    }
}

std::string search(const char* pattern, const char* input, size_t& pos)
{
    std::cmatch res;
    std::regex_search(input, res, std::regex(pattern));
    pos += res[0].length();
    return res[0];
}
}

std::vector<Token> Lexer::getAllToken()
{
    std::vector<Token> ret;
    for (Token i = token(); i.m_tokenKind != TokenKind::NONE; i = nextToken()) {
        ret.push_back(i);
    }
    return ret;
}

Token Lexer::nextToken()
{
    m_currentTok = nextTokenImpl();
    return m_currentTok;
}

Token Lexer::nextTokenImpl()
{
    removeDelimiters(m_input, m_pos);
    const char ch = m_input[m_pos];

    const char* double_reg = "-?[0-9]+(\\.[0-9]*)?";
    const char* id_reg = "[a-zA-Z][a-zA-Z0-9_]*";

    const char* ch_start = m_input.c_str() + m_pos;
    if (isdigit(ch)) {
        return Token(TokenKind::NUMBER, search(double_reg, ch_start, m_pos));
    } else if (isalpha(ch)) {
        return Token(TokenKind::IDENTIFIER, search(id_reg, ch_start, m_pos));
    }

    m_pos += 1;
    if (ch == '+') {
        return Token(TokenKind::PLUS);
    } else if (ch == '-') {
        return Token(TokenKind::MINUS);
    } else if (ch == '*') {
        return Token(TokenKind::MULT);
    } else if (ch == '/') {
        return Token(TokenKind::DIV);
    } else if (ch == '{') {
        return Token(TokenKind::LEFT_BRACE);
    } else if (ch == '}') {
        return Token(TokenKind::RIGHT_BRACE);
    } else if (ch == ')') {
        return Token(TokenKind::RIGHT_BRACKET);
    } else if (ch == '(') {
        return Token(TokenKind::LEFT_BRACKET);
    }
    return Token(TokenKind::NONE);
}
