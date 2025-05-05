#include "OutputHandler.h"

#include <iostream>

void OutputHandler::dumpUniverse(GameUniverse universe, string file_name) {
    uniWriter.writeUniverse(universe, file_name);
}

void OutputHandler::printUniverse(GameUniverse universe) {
    int rows = universe.getRows();
    int cols = universe.getCols();

    string name = "Universe name: " + universe.getUniverseName();
    string rules = "Universe rules: " + universe.getRules();
    string iterations = "Universe iterations: " + to_string(universe.getGeneration());

    cout << name << "|" << rules << "|" << iterations << endl;
    vector<vector<bool>> board = universe.getField();

    for (int i = 0; i < rows; ++i) {
        cout << "_";
    }
    cout << endl;
    for (auto row : board) {
        string string_row = "| ";
        for (int i = 0; i < cols; ++i) {
            if (row[i]) {
                string_row =+ "+";
            } else {
                string_row += " ";
            }
        }
        string_row += " |";
        cout << string_row << endl;
    }
    for (int i = 0; i < rows; ++i) {
        cout << "-" << endl;
    }
}

void OutputHandler::sendHelp(string message) {
    if (message != "") {
        cerr << message << endl;
    }
    cerr << help_message << endl;
}
