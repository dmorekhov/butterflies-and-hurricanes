#ifndef TASK_0_FILEWRITER_H
#define TASK_0_FILEWRITER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FileWriter {
private:
    string file_name;
    ofstream file_stream;
public:
    FileWriter(string file_name);
    void OpenFile();
    void Write(vector<string> &data);
    void CloseFile();
};

#endif //TASK_0_FILEWRITER_H
