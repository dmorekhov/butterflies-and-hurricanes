#include "Game.h"

#include <iostream>

void Game::startGame() {
    cout << "Game started" << endl;
    output_handler.printUniverse(game_universe);

    GameField game_field = game_universe.getGameField();
    cout << "Command: ";
    string command;
    while (command_controller.GameStatus()) {
        getline(cin, command);
        command_controller.commandProcessing(command, game_field);
        if (command_controller.GameStatus()) {
            cout << "Command: ";
        }
    }
};

Game::Game(const string& input_file) : game_universe(UniReader::readFile(input_file)), command_controller(game_universe) {}

void Game::startGame(const string& output_file, const int& ticks) {
    game_universe.iterateGame(ticks);

    output_handler.dumpUniverse(game_universe, output_file);
}
