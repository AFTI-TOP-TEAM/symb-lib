#include "symblib/parser/lexer/Lexer.h"
#include "gtest/gtest.h"

TEST(TestLexer, test1)
{
    const auto token = Lexer("+").token();
    ASSERT_EQ(token.m_tokenKind, TokenKind::PLUS);
}

TEST(TestLexer, test2)
{
    const auto token = Lexer("  +  ").token();
    ASSERT_EQ(token.m_tokenKind, TokenKind::PLUS);
}

TEST(TestLexer, test3)
{
    const auto token = Lexer("8.8").token();
    ASSERT_EQ(token.m_str, "8.8");
    ASSERT_EQ(token.m_tokenKind, TokenKind::NUMBER);
}

TEST(TestLexer, test4)
{
    const auto token = Lexer("    8.8\t").token();
    ASSERT_EQ(token.m_str, "8.8");
    ASSERT_EQ(token.m_tokenKind, TokenKind::NUMBER);
}

TEST(TestLexer, test5)
{
    const std::vector<Token> token = Lexer("    8.8\t + 6").getAllToken();
    ASSERT_EQ(token[0].m_str, "8.8");
    ASSERT_EQ(token[0].m_tokenKind, TokenKind::NUMBER);

    ASSERT_EQ(token[1].m_tokenKind, TokenKind::PLUS);
    ASSERT_EQ(token[2].m_tokenKind, TokenKind::NUMBER);
    ASSERT_EQ(token[2].m_str, "6");
}

TEST(TestLexer, test6)
{
    const std::vector<Token> token = Lexer("(8.8 + 6)  * name").getAllToken();

    ASSERT_EQ(token[0].m_tokenKind, TokenKind::LEFT_BRACKET);

    ASSERT_EQ(token[1].m_str, "8.8");
    ASSERT_EQ(token[1].m_tokenKind, TokenKind::NUMBER);

    ASSERT_EQ(token[2].m_tokenKind, TokenKind::PLUS);

    ASSERT_EQ(token[3].m_str, "6");
    ASSERT_EQ(token[3].m_tokenKind, TokenKind::NUMBER);

    ASSERT_EQ(token[4].m_tokenKind, TokenKind::RIGHT_BRACKET);

    ASSERT_EQ(token[5].m_tokenKind, TokenKind::MULT);

    ASSERT_EQ(token[6].m_str, "name");
    ASSERT_EQ(token[6].m_tokenKind, TokenKind::IDENTIFIER);
}

TEST(TestLexer, test7)
{
    const std::vector<Token> token = Lexer("    8.8\t + 6").getAllToken();
    ASSERT_EQ(token[0].m_str, "8.8");
    ASSERT_EQ(token[0].m_tokenKind, TokenKind::NUMBER);

    ASSERT_EQ(token[1].m_tokenKind, TokenKind::PLUS);

    ASSERT_EQ(token[2].m_tokenKind, TokenKind::NUMBER);
    ASSERT_EQ(token[2].m_str, "6");
}

TEST(TestLexer, test8)
{
    const std::vector<Token> token = Lexer("(8.8+6)*name").getAllToken();

    ASSERT_EQ(token[0].m_tokenKind, TokenKind::LEFT_BRACKET);

    ASSERT_EQ(token[1].m_str, "8.8");
    ASSERT_EQ(token[1].m_tokenKind, TokenKind::NUMBER);

    ASSERT_EQ(token[2].m_tokenKind, TokenKind::PLUS);

    ASSERT_EQ(token[3].m_str, "6");
    ASSERT_EQ(token[3].m_tokenKind, TokenKind::NUMBER);

    ASSERT_EQ(token[4].m_tokenKind, TokenKind::RIGHT_BRACKET);

    ASSERT_EQ(token[5].m_tokenKind, TokenKind::MULT);

    ASSERT_EQ(token[6].m_str, "name");
    ASSERT_EQ(token[6].m_tokenKind, TokenKind::IDENTIFIER);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
