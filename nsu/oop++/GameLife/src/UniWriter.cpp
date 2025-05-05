#include "UniWriter.h"

#include <iostream>

void UniWriter::writeUniverse(GameUniverse& game_universe, string& file_name) {
    ofstream output_file(file_name);
    if (!output_file.is_open()) {
        throw runtime_error("Error opening output file " + file_name);
    }
    output_file << "#N " << game_universe.getUniverseName() << endl;
    output_file << game_universe.rules.getGameRules() << endl;
    output_file << "#S " << game_universe.field.getRows() << " " << game_universe.field.getCols() << endl;
    for (int i = 0; i < game_universe.field.getRows(); i++) {
        for (int j = 0; j < game_universe.field.getCols(); j++) {
            if (game_universe.field.getCell(i, j)) {
                output_file << i << " " << j << endl;
            }
        }
    }
    output_file.close();
}
