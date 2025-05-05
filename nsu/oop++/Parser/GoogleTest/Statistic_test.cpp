#include "gtest/gtest.h"
#include "../Statistic.h"

using namespace std;

TEST(StatisticTestSuite, EMPTY_LIST) {
    Statistic test_list;
    vector<pair<string ,int>> stats = test_list.GetStats();
    ASSERT_EQ(stats.size(), 0);
}

TEST(StatisticTestSuite, REGULAR_LIST) {
    Statistic test_list;
    string test_input = "silent";
    for (int i = 0; i < 3; ++i) {
        test_list.AddWord(test_input);
    }
    test_input = "hill";
    for (int i = 0; i < 4; ++i) {
        test_list.AddWord(test_input);
    }
    ASSERT_EQ(test_list.GetStats().size(), 2);
    ASSERT_EQ(test_list.GetCounter(), 7);

    vector<pair<string ,int>> stats = test_list.GetStats();
    ASSERT_EQ(stats[0].first, "hill");
    ASSERT_EQ(stats[0].second, 4);
    ASSERT_EQ(stats[1].first, "silent");
    ASSERT_EQ(stats[1].second, 3);
}