#include "SymbolManager.h"
#include <iostream>

using namespace std;

SymbolManager::SymbolManager() {}

SymbolManager::~SymbolManager() {
    all_symbols.clear();
    short_symbols.clear();
}

void SymbolManager::loadSymbols(const QString &filePath) {
    all_symbols = JsonReader::loadFile(filePath);
}

void SymbolManager::printSymbols() {
    if (all_symbols.isEmpty()) {
        cout << "No symbols found" << endl;\
        return;
    }
    for (const auto& symbol : all_symbols) {
        qDebug() << symbol;
    }
}
