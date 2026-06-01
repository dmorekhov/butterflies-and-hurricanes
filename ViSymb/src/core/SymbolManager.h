#ifndef SYMBOLMANAGER_H
#define SYMBOLMANAGER_H

#include <QHash>
#include <QString>
#include <QDebug>
#include "JsonReader.h"

using namespace std;

class SymbolManager {
private:
    QList<Symbol> all_symbols;
    QHash<QString, QString> short_symbols;
public:
    SymbolManager();
    ~SymbolManager();
    void loadSymbols(const QString &filePath);
    void printSymbols();
};


#endif //SYMBOLMANAGER_H
