#include "GameField.h"

#include <stdexcept>

GameField::GameField() {
    rows = 0;
    cols = 0;
    board = vector<vector<bool>>(rows, vector<bool>(cols, false));
}

void GameField::clearBoard() {
    rows = 0;
    cols = 0;
    board.clear();
}

GameField::~GameField() {
    clearBoard();
}

GameField::GameField(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    board = vector<vector<bool>>(rows, vector<bool>(cols, false));
}

void GameField::setCell(const int& row, const int& col, const bool& value) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Row or col out of range");
    }
    board[row][col] = value;
}

bool GameField::getCell(const int& row, const int& col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Row or col out of range");
    }
    return board[row][col];
}

int GameField::getNeighborsCount(const int& row, const int& col) {
    int counter = 0;
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Row or col out of range");
    }
    for (int row_shift = -1; row_shift <= 1; ++row_shift) { // -1 -- to left, 0 -- same, 1 -- to right
        for (int col_shift = -1; col_shift <= 1; col_shift++) { // -1 -- to bottom, 0 -- same, 1 -- to upper
            int diff_row = row;
            if (row_shift < 0 && diff_row == row) {
                diff_row = rows - 1;
            } else if (row_shift > 0 && diff_row + 1 == rows) {
                diff_row = 0;
            } else {
                diff_row++;
            }

            int diff_col = col;
            if (col_shift < 0 && diff_col == col) {
                diff_col = cols - 1;
            } else if (col_shift > 0 && diff_col + 1 == cols) {
                diff_col = 0;
            } else {
                diff_col++;
            }

            if (getCell(diff_row, diff_col) && (diff_row != row || diff_col != col)) {
                counter++;
            }
        }
    }
    return counter;
}

vector<vector<bool>> GameField::getGameBoard() const {
    return board;
}

int GameField::getRows() const {
    return rows;
}

int GameField::getCols() const {
    return cols;
}
