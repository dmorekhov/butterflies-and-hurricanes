#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <string>
#include <vector>
#include "GameUniverse.h"
#include "UniWriter.h"
#include "OutputHandler.h"

using namespace std;

class CommandHandler {
public:
    virtual ~CommandHandler() = default;
    virtual void handleCommand(vector<string>& arguments, GameUniverse& universe, GameField& field, bool& game_status) const = 0;
};

class DumpCommandHandler : public CommandHandler {
public:
    void handleCommand(vector<string>& arguments, GameUniverse& universe, GameField& field, bool& game_status) const override;
};

class TickCommandHandler : public CommandHandler {
public:
    void handleCommand(vector<string>& arguments, GameUniverse& universe, GameField& field, bool& game_status) const override;
};

class ExitCommandHandler : public CommandHandler {
public:
    void handleCommand(vector<string>& arguments, GameUniverse& universe, GameField& field, bool& game_status) const override;
};

class HelpCommandHandler : public CommandHandler {
public:
    void handleCommand(vector<string>& arguments, GameUniverse& universe, GameField& field, bool& game_status) const override;
};

#endif //COMMANDHANDLER_H
