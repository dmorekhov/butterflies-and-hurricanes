#include "gtest/gtest.h"
#include "../FileWriter.h"

using namespace std;

TEST(FileWriterTestSuite, REGULAR_STRING) {
    FileWriter fw("test.txt");
    fw.OpenFile();


    int totalWords = 10;
    vector<string> information;
    information.push_back("Aboba");
    information.push_back(to_string(3));
    information.push_back(to_string((double) 3 / totalWords * 100));
    fw.Write(information);
    information.clear();
    information.push_back("Baby");
    information.push_back(to_string(5));
    information.push_back(to_string((double) 5 / totalWords * 100));
    fw.Write(information);
    information.clear();
    information.push_back("Coco");
    information.push_back(to_string(2));
    information.push_back(to_string((double) 2 / totalWords * 100));
    fw.Write(information);
    fw.CloseFile();

    ifstream file("test.txt");
    string line;
    getline(file, line);
    ASSERT_EQ(line, "Aboba; 3; 30.000000");
    getline(file, line);
    ASSERT_EQ(line, "Baby; 5; 50.000000");
    getline(file, line);
    ASSERT_EQ(line, "Coco; 2; 20.000000");

    getline(file, line);
    ASSERT_EQ(line, "");
    ASSERT_TRUE(file.eof());
}
