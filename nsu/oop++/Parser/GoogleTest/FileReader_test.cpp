#include "gtest/gtest.h"
#include "../FileReader.h"

using namespace std;

TEST(FileReaderTestSuite, EMPTY_FILE) {
    ofstream test_file("empty.txt");
    test_file.close();

    FileReader file_reader("empty.txt");
    file_reader.OpenFile();

    ASSERT_EQ(file_reader.GetNext(), "");
    ASSERT_FALSE(file_reader.HasNext());
}

TEST(FileReaderTestSuite, ONE_STRING) {
    ofstream test_file("testfile.txt");
    test_file << "Something else";
    test_file.close();

    FileReader file_reader("testfile.txt");
    file_reader.OpenFile();

    ASSERT_EQ(file_reader.GetNext(), "Something else");
    ASSERT_FALSE(file_reader.HasNext());
}
// ASSERT_FALSE
// ASSERT_TRUE
// ASSERT_EQ