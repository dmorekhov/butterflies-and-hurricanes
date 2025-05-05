#ifndef TASK_0_STATISTIC_H
#define TASK_0_STATISTIC_H

#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Statistic {
private:
    unordered_map<string, int> stats;
    int word_counter;
public:
    Statistic();
    void AddWord(string &word);
    vector<pair<string, int>> GetStats();
    int GetCounter();
};

#endif //TASK_0_STATISTIC_H
