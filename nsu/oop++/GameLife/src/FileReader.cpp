#include "FileReader.h"

#include <stdbool.h>

bool FileReader::isOpen() const {
    return file.is_open();
}

bool FileReader::isEOF() {
    if (file.is_open()) {
        return file.peek() == EOF;
    }
    return true;
}

void FileReader::open(const string& file_name) {
    if (!isOpen()) {
        file.open(file_name);
    }
}

void FileReader::close() {
    if (isOpen()) {
        file.close();
    }
}

string FileReader::getLine() {
    string line;
    if (!isEOF()) {
        getline(file, line);
    }
    return line;
}
