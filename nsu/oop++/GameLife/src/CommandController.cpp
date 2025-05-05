#include <sstream>
#include "CommandController.h"

#include <iostream>

CommandController::CommandController(GameUniverse& universe) : universe(universe) {
    handlers["dump"] = new DumpCommandHandler();
    handlers["tick"] = new TickCommandHandler();
    handlers["t"] = handlers["tick"];
    handlers["help"] = new HelpCommandHandler();
    handlers["exit"] = new ExitCommandHandler();
}

CommandController::~CommandController() {
    for (auto& pair : handlers) {
        delete pair.second;
    }
    handlers.clear();
}

void CommandController::commandProcessing(const string& command_string, GameField& field) {
    istringstream ss(command_string);
    string command;
    ss >> command;

    vector<string> tokens;
    string argument;
    while (ss >> argument) {
        tokens.push_back(argument);
    }

    const auto it = handlers.find(command);
    if (it == handlers.end()) {
        cerr << "Command not found: " << command << endl;
    } else {
        it->second->handleCommand(tokens, universe, field, game_status);
    }
}

bool CommandController::GameStatus() {
    return game_status;
}

