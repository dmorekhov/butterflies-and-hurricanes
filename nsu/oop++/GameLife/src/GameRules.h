#ifndef GAMERULES_H
#define GAMERULES_H

#include <array>
#include <string>

using namespace std;

class GameRules {
private:
    array<bool, 9> birthRules;
    array<bool, 9> survivalRules;
public:
    GameRules() = default;
    GameRules(const string &birthRule, const string &survivalRule);
    GameRules(string& rules);

    bool checkBirthRule(int& liveNeighbours);
    bool checkSurvivalRule(int& liveNeighbours);

    array<bool, 9> getBirthRules();
    array<bool, 9> getSurvivalRules();
    string getGameRules();

    void PrintBirthRules();
    void PrintSurvivalRules();
};


#endif //GAMERULES_H
