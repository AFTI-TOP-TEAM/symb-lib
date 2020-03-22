#include "symblib/Nodes.h"
#include "symblib/parser/Location.h"
#include "symblib/parser/parser/Parser.h"
#include "gtest/gtest.h"

TEST(TestParser, test1)
{
    auto lex = Lexer("3 + 4 + 6");
    parser::RecursiveParser parser;
    parser.parse(lex);
    auto tree = parser.getResult();
    ASSERT_EQ(tree->GetType(), "+");
    auto p = static_cast<symb::Sum*>(tree.release());
    //ASSERT_EQ(p->GetLeftArg()->GetType(), "Const");
}

TEST(TestParser, test2)
{
    auto lex = Lexer("3 * 4 + 6");
    parser::RecursiveParser parser;
    parser.parse(lex);
    auto tree = parser.getResult();
    ASSERT_EQ(tree->GetType(), "+");
}

TEST(TestParser, test3)
{
    auto lex = Lexer("3 * 4 + 6 + 6");
    parser::RecursiveParser parser;
    parser.parse(lex);
    auto tree = parser.getResult();
    ASSERT_EQ(tree->GetType(), "+");
}

TEST(TestParser, test4)
{
    auto lex = Lexer("3 + +");
    parser::RecursiveParser parser;
    ASSERT_THROW(parser.parse(lex), parser::Location);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
