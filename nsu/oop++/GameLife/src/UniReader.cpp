#include "UniReader.h"
#include <sstream>
#include <iostream>

// string UniReader::getParameter(string line) {
//     if (!has_line) {
//         file_line = fileReader.getLine();
//         has_line = true;
//     }
//
//     if (file_line.find(line) == 0) {
//         has_line = false;
//         return string(file_line, line.size());
//     }
//     return string();
// }

void UniReader::getName(const string& line, string& universe_name, bool& name_flag) {
    if (line.empty()) {
        universe_name = "Universe";
        cerr << "No universe name. Using Default" << endl;
    } else {
        universe_name = line;
    }
    name_flag = true;
}

void UniReader::getRules(const string& line, GameRules& universe_rules, bool& rules_flag) {
    string rule_string = line.substr(3);
    const int pos = line.find('/');
    if (pos == string::npos) {
        cerr << "No rules found. Using Default" << endl;
        universe_rules = GameRules("B3", "S23");
    } else {
        const string birth_rule = rule_string.substr(0, pos);
        const string survive_rule = rule_string.substr(pos + 1);
        universe_rules = GameRules(birth_rule, survive_rule);
    }
    rules_flag = true;
}

void UniReader::getSize(const string& line, pair<int, int>& universe_size, bool& has_size) {
    istringstream iss(line.substr(3));
    has_size = true;
    int x = 0, y = 0;
    if (!(iss >> x)) {
        cerr << "Invalid size. Using Default: 40x40" << endl;
        has_size = false;
        return;
    }
    if (!(iss >> y)) {
        cerr << "Invalid size. Using Default: 40x40" << endl;
        has_size = false;
        return;
    }
    universe_size.first = x;
    universe_size.second = y;
}

void UniReader::getCells(const string& line, const pair<int, int>& universe_size, vector<pair<int, int>>& alive_cells, bool& has_size, bool& has_cells) {
    istringstream iss(line);
    int x, y;
    if (!(iss >> x >> y)) {
        cerr << "Invalid format. Skip" << endl;
        return;
    }
    if (x < 0 || (x >= universe_size.first && has_size) || y < 0 || (y >= universe_size.second && has_size)) {
        cerr << "Wrong coords: " << x << ", " << y << endl;
        return;
    }
    const pair<int, int> cell = make_pair(x, y);
    alive_cells.push_back(cell);
    has_cells = true;
}

GameUniverse UniReader::readFile(const string& file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        throw runtime_error("Could not open file " + file_name);
    }

    string line;
    string name;
    GameRules universe_rules;
    int rows = 0, cols = 0;
    pair<int, int> size = make_pair(rows, cols);
    vector<pair<int, int>> alive_cells;
    bool has_name = false;
    bool has_rule = false;
    bool has_size = false;
    bool has_cells = false;
    getline(file, line);
    if (line != "#Life 1.06") {
        cerr << ("Error: wrong format") << endl;
        throw exception();
    }
    while (getline(file, line)) {
        if ((line.empty() || line[0] == '#') && !has_cells) {
            if (line.find("#N ") == 0 && !has_name) {
                getName(line, name, has_name);
            } else if (line.find("#R ") == 0 && !has_rule) {
                getRules(line, universe_rules, has_rule);
            } else if (line.find("#S ") == 0 && !has_size) {
                getSize(line, size , has_size);
            }
        } else {
            getCells(line, size, alive_cells, has_size, has_cells);
        }
    }

    // string rules_part = getParameter("#R ");
    // getRules(rules_part, universe_rules);
    //
    // string size_part = getParameter("#S ");
    // getSize(size_part, universe_size);
    //
    // while (!fileReader.isEOF()) {
    //     getCells(getParameter(), alive_cells);
    // }
    //
    // fileReader.close();
    file.close();
    GameUniverse universe(name, size.first, size.second, universe_rules, alive_cells);
    return universe;
}
