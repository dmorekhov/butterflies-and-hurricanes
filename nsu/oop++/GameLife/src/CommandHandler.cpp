#include "CommandHandler.h"

#include <iostream>

void DumpCommandHandler::handleCommand(vector<string>& arguments, GameUniverse& universe, GameField& field, bool& game_status) const {
    if (arguments.size() != 1) {
        cerr << "Usage: dump <input_file>" << endl;
        return;
    }
    UniWriter::writeUniverse(universe, arguments[0]);
    cout << "Universe saved: " + arguments[0] << endl;
}

void TickCommandHandler::handleCommand(vector<string>& arguments, GameUniverse& universe, GameField& field, bool& game_status) const {
    int n = 1;
    if (arguments.size() == 1) {
        try {
            n = stoi(arguments[0]);
        } catch (invalid_argument& e) {
            cerr << "Invalid ticks. Using Default n = 1" << endl;
        }
    }
    for (int i = 0; i < n; ++i) {
        universe.iterateGame(n);
    }
    OutputHandler output;
    output.printUniverse(universe);
}

void ExitCommandHandler::handleCommand(vector<string>& arguments, GameUniverse& universe, GameField& field, bool& game_status) const {
    game_status = false;
    cout << "Exiting..." << endl;
}

void HelpCommandHandler::handleCommand(vector<string>& arguments, GameUniverse& universe, GameField& field, bool& game_status) const {
    OutputHandler output;
    output.sendHelp("");
}

