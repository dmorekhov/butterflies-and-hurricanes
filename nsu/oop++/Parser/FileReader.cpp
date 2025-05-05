#include "FileReader.h"

using namespace std;

FileReader::FileReader(string file_name) {
    this->file_name = file_name;
}

void FileReader::OpenFile() {
    file_stream.open(file_name);
}

bool FileReader::HasNext() {
    return !file_stream.eof();
}

string FileReader::GetNext() {
    if (HasNext()) {
        string line;
        getline(file_stream, line);
        return line;
    }
    return "";
}

void FileReader::CloseFile() {
    file_stream.close();
}