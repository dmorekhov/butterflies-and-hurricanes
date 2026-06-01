#include "JsonReader.h"

#include <iostream>

JsonReader::JsonReader() :symbols() {}

JsonReader::~JsonReader() {
    symbols.clear();
}

QList<Symbol> JsonReader::loadFile(const QString& filePath) {
    QList<Symbol> parsed_symbols;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file: " << filePath;
        return parsed_symbols;
    }
    QByteArray data = file.readAll();
    // qDebug() << "File contents: " << data;
    file.close();

    QJsonParseError parse_error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &parse_error);
    if (parse_error.error != QJsonParseError::NoError) {
        qDebug() << "Failed to parse file: " << filePath;
        return parsed_symbols;
    }
    if (!jsonDoc.isObject()) {
        qDebug() << "JSON-file is not an object: " << filePath;
        return parsed_symbols;
    }

    QJsonObject root = jsonDoc.object();
    QJsonArray symbols_array = root["symbols"].toArray();
    for (const QJsonValue &value : symbols_array) {
        QJsonObject symbol_object = value.toObject();
        Symbol new_symbol;
        new_symbol.name = symbol_object["name"].toString();
        new_symbol.character = symbol_object["character"].toString();
        new_symbol.usage_count = symbol_object["usage_count"].toInt(0);

        QJsonArray symbol_tags = symbol_object["tags"].toArray();
        for (const QJsonValue &tag : symbol_tags) {
            new_symbol.shortcuts.append(tag.toString());
        }

        QJsonArray symbol_shortcuts = symbol_object["shortcuts"].toArray();
        for (const QJsonValue &shortcut : symbol_shortcuts) {
            new_symbol.shortcuts.append(shortcut.toString());
        }
        parsed_symbols.append(new_symbol);
    }
    return parsed_symbols;
}


