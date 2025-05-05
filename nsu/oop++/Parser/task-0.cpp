#include "FileReader.h"
#include "Parser.h"
#include "Statistic.h"
#include "FileWriter.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Not 3";
        return 0;
    }

    string input_file = argv[1];
    FileReader file_reader(input_file);
    file_reader.OpenFile();
    Parser parser;
    Statistic stats;
    while (file_reader.HasNext()) {
        string line = file_reader.GetNext();
        vector<string> words = parser.Parse(line);
        for (auto &word : words) {
            stats.AddWord(word);
        }
    }
    file_reader.CloseFile();

    string output_file = argv[2];
    FileWriter file_writer(output_file);
    file_writer.OpenFile();
    vector<pair<string, int>> words_stats = stats.GetStats();
    int total_words = stats.GetCounter();
    for (auto &currentPair : words_stats) {
        vector<string> iterateData;
        iterateData.push_back(currentPair.first);
        iterateData.push_back(to_string(currentPair.second));
        iterateData.push_back(to_string((double) currentPair.second / total_words * 100));
        file_writer.Write(iterateData);
    }
    file_writer.CloseFile();
    
    return 0;
}
