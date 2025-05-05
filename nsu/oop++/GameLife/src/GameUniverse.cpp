#include "GameUniverse.h"

#include <stdexcept>

GameUniverse::GameUniverse() {
    gen = 1;
    field = GameField();
}

GameUniverse::GameUniverse(const string& name, const int& rows, const int& cols, const GameRules& game_rules, vector<pair<int, int>> alive_cells) {
    gen = 1;
    field = GameField(rows, cols);
    universe_name = name;
    rules = game_rules;
    setAlive(alive_cells);
}

void GameUniverse::setUniverseName(const string& name) {
    universe_name = name;
}

string GameUniverse::getUniverseName() {
    return universe_name;
}

int GameUniverse::getGeneration() {
    return gen;
}


GameField GameUniverse::getGameField() {
    return field;
}

string GameUniverse::getRules() {
    return rules.getGameRules();
}

int GameUniverse::getRows() {
    return field.getRows();
}

int GameUniverse::getCols() {
    return field.getCols();
}

void GameUniverse::iterateGame(int iterations) {
    if (iterations < 0) {
        throw out_of_range("Iterations must be greater than 0.");
    }
    for (int i = 0; i < iterations; ++i) {
        nextGeneration();
    }
}


void GameUniverse::nextGeneration() {
    const int rows = field.getRows();
    const int cols = field.getCols();
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            bool live_cell = field.getCell(x, y);
            int neighbours_counter = field.getNeighborsCount(x, y);
            if (live_cell) {
                field.setCell(x, y, rules.checkSurvivalRule(neighbours_counter));
            } else {
                field.setCell(x, y, rules.checkBirthRule(neighbours_counter));
            }
        }
    }
    ++gen;
}



vector<vector<bool>> GameUniverse::getField() {
    return field.getGameBoard();
}

void GameUniverse::setAlive(vector<pair<int, int>>& cells) {
    for (pair<int, int> cell : cells) {
        if (cell.first > field.getRows() || cell.second > field.getCols()) {
            throw invalid_argument("Cell out of range");
        }
        field.setCell(cell.first, cell.second, true);
    }
}

vector<pair<int, int>> GameUniverse::getAliveCells() {
    vector<pair<int, int>> cells;
    for (int x = 0; x < field.getRows(); ++x) {
        for (int y = 0; y < field.getCols(); ++y) {
            if (field.getCell(x, y)) {
                cells.push_back(make_pair(x, y));
            }
        }
    }
    return cells;
}


