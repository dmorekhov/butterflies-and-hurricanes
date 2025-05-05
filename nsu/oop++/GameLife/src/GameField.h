#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <vector>

using namespace std;

class GameField {
private:
    vector<vector<bool>> board;
    int rows;
    int cols;
public:
    GameField();
    ~GameField();
    GameField(int rows, int cols);

    void setCell(const int& row, const int& col, const bool& value);
    bool getCell(const int& row, const int& col);
    int getNeighborsCount(const int& row, const int& col);

    vector<vector<bool>> getGameBoard() const;

    int getRows() const;
    int getCols() const;

    void clearBoard();
};

#endif //GAMEFIELD_H
