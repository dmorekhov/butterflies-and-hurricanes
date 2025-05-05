#ifndef GAMEUNIVERSE_H
#define GAMEUNIVERSE_H

#include "GameField.h"
#include "GameRules.h"

using namespace std;

class GameUniverse {
private:
    GameField field;
    GameRules rules;

    int gen;
    string universe_name;

    vector<pair<int, int>> alive_cells;
public:
    GameUniverse();
    GameUniverse(const string& name, const int& rows, const int& cols, const GameRules& game_rules, vector<pair<int, int>> alive_cells);

    void setSize(int rows, int cols);

    void setUniverseName(const string& name);
    string getUniverseName();
    GameField getGameField();

    string getRules();
    int getRows();
    int getCols();

    void iterateGame(int iterations = 1);
    void nextGeneration();
    int getGeneration();

    vector<vector<bool>> getField();
    void setAlive(vector<pair<int, int>>& cells);
    vector<pair<int, int>> getAliveCells();

    friend class UniWriter;
};



#endif //GAMEUNIVERSE_H
