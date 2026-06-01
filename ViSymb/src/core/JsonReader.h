#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QString>
#include <QList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>
#include <QJsonArray>

using namespace std;

struct Symbol {
    QString name;
    QString character;
    QStringList tags;
    QStringList shortcuts;
    int usage_count = 0;

};

inline QDebug operator<<(QDebug dbg, const Symbol &symbol) {
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "Symbol " << symbol.name << '\n' << symbol.character << '\n' << symbol.tags << symbol.shortcuts << '\n' << symbol.usage_count << "";
    return dbg;
}

class JsonReader {
private:
    QList<Symbol> symbols;
public:
    JsonReader();
    ~JsonReader();
    static QList<Symbol> loadFile(const QString &filePath);
};

#endif //JSONPARSER_H
