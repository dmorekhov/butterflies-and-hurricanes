#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <string>
#include <map>
#include "GameUniverse.h"
#include "CommandHandler.h"

using namespace std;

class CommandController {
private:
    map<string, CommandHandler*> handlers;
    bool game_status = true;
    GameUniverse& universe;
public:
    explicit CommandController(GameUniverse& universe);
    ~CommandController();
    bool GameStatus();
    void commandProcessing(const string& command_string, GameField& field);
};

#endif //COMMANDCONTROLLER_H
