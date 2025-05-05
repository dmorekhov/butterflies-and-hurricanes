#ifndef UNIWRITER_H
#define UNIWRITER_H

#include "GameUniverse.h"
#include <fstream>

using namespace std;

class UniWriter {
public:
    static void writeUniverse(GameUniverse& game_universe, string& file_name);
};

#endif //UNIWRITER_H
