#include "gtest/gtest.h"
#include "../Parser.h"

using namespace std;

TEST(ParserTestSuite, EMPTY_STRING) {
    Parser parser;
    string test_string = "";
    vector<string> test_result = parser.Parse(test_string);

    ASSERT_EQ(test_result.size(), 0);
}

TEST(ParserTestSuite, SPACE_STRING) {
    Parser parser;
    string test_string = "\t \t \t \t \t \t";
    vector<string> test_result = parser.Parse(test_string);
    ASSERT_EQ(test_result.size(), 0);
}

TEST(ParserTestSuite, DEFAULT_STRING) {
    Parser parser;
    string test_string = "Hey my man how are you doing";

    vector<string> test_result = parser.Parse(test_string);
    ASSERT_EQ(test_result.size(), 7);
    ASSERT_EQ(test_result[0], "hey");
    ASSERT_EQ(test_result[1], "my");
    ASSERT_EQ(test_result[2], "man");
    ASSERT_EQ(test_result[3], "how");
    ASSERT_EQ(test_result[4], "are");
    ASSERT_EQ(test_result[5], "you");
    ASSERT_EQ(test_result[6], "doing");
}