#ifndef UNIREADER_H
#define UNIREADER_H

#include "GameUniverse.h"
#include "FileReader.h"

using namespace std;

class UniReader {
private:
    // FileReader fileReader;
    //
    // string universe_name = "Universe";
    // GameRules universe_rules = GameRules("B3", "S23");
    // pair<int, int> universe_size = {40, 40};
    // vector <pair<int, int>> alive_cells = {{10, 10}, {10, 11}, {20, 20}, {20, 19}, {20, 18},
                                    // {3, 3}, {4, 2}, {8, 5}};
    // bool name_flag;
    // bool rules_flag;
    // bool size_flag;
    // bool cells_flag;
    //
    // bool has_line;
    //
    // string file_line;
    //
    // string getParameter(string line="");
    //
    static void getName(const string& line, string& universe_name, bool& has_name);
    static void getRules(const string& line, GameRules& universe_rules, bool& has_rules);
    static void getSize(const string& line, pair<int, int>& universe_size, bool& has_size);
    static void getCells(const string& line, const pair<int, int>& universe_size, vector<pair<int, int>>& alive_cells, bool& has_size, bool& has_cells);
public:
    static GameUniverse readFile(const string& file_name);
};

#endif