#include "FileWriter.h"

using namespace std;

FileWriter::FileWriter(std::string file_name) {
    this->file_name = file_name;
}

void FileWriter::OpenFile() {
    file_stream.open(file_name);
}

void FileWriter::Write(vector<string> &data) {
    for (int i = 0; i < data.size() - 1; ++i) {
        file_stream << data[i] << "; ";
    }
    file_stream << data[data.size() - 1] << '\n';
}
void FileWriter::CloseFile() {
    file_stream.close();
}
