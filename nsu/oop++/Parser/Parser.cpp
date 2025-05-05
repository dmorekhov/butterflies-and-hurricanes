#include "Parser.h"

using namespace std;

vector<string> Parser::Parse(std::string &line) {
    vector<string> words;
    string word;
    bool flag = false;
    for (auto &symbol : line) {
        if (isalnum(symbol)) {
            word += tolower(symbol);
            flag = true;
        }
        else if (flag) {
            words.push_back(word);
            word.clear();
            flag = false;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}