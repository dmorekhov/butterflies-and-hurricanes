#ifndef TASK_0_FILEREADER_H
#define TASK_0_FILEREADER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;
class FileReader {
private:
    string file_name;
    ifstream file_stream;
public:
    FileReader(string file_name);
    void OpenFile();
    bool HasNext();
    string GetNext();
    void CloseFile();
};

#endif //TASK_0_FILEREADER_H
