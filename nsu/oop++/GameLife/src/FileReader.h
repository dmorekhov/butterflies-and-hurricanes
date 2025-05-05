#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <fstream>

using namespace std;

class FileReader {
private:
    ifstream file;
public:
    bool isOpen() const;
    bool isEOF();
    void open(const string& file_name);
    void close();
    string getLine();
};

#endif //FILEREADER_H
