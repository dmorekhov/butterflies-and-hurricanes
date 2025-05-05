#ifndef OUTPUTHANDLER_H
#define OUTPUTHANDLER_H

#include "UniWriter.h"
#include "GameUniverse.h"

using namespace std;

class OutputHandler {
private:
    UniWriter uniWriter;

    string help_message =
        "Commands:\n"
        "dump <filename> -> save universe to file\n"
        "tick <n> (Default n = 1) - iterate universe n times and print it\n"
        "exit - finish the game\n"
        "help - print this message again";
public:
    void dumpUniverse(GameUniverse universe, string file_name);
    static void printUniverse(GameUniverse universe);
    void sendHelp(string message);
};

#endif //OUTPUTHANDLER_H
