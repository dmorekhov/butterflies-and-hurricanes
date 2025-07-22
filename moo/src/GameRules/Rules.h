#ifndef RULES_H
#define RULES_H

#include <vector>

using namespace std;

class Rules {
private:
    unsigned short word_length;
    vector<char> word;
public:
    Rules();
    ~Rules();

};

#endif //RULES_H
