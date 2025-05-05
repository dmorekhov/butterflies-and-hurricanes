#ifndef GAME_H
#define GAME_H

#include "UniReader.h"
#include "CommandController.h"

class Game {
private:
    CommandController command_controller;
    UniReader universe_reader;
    GameUniverse game_universe;
    OutputHandler output_handler;
public:
    explicit Game(const string& filename);
    void startGame();
    void startGame(const string& output_file, const int& ticks);
};

#endif //GAME_H
