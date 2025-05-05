#include "Statistic.h"

using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.second > b.second;
}

Statistic::Statistic() {
    word_counter = 0;
}

void Statistic::AddWord(std::string &word) {
    ++stats[word];
    ++word_counter;
}

vector<pair<string, int>> Statistic::GetStats() {
    vector<pair<string, int>> sorted_stats;
    sorted_stats.resize(stats.size());
    copy(stats.begin(), stats.end(), sorted_stats.begin());
    sort(sorted_stats.begin(), sorted_stats.end(), cmp);
    return sorted_stats;
}

int Statistic::GetCounter() {
    return word_counter;
}
