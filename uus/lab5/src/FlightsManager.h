#ifndef FLIGHTSMANAGE_H
#define FLIGHTSMANAGE_H

#include "FlightsInfo.h"
#include "FlightsStats.h"
#include "FlightsSearcher.h"

class FlightsManager {
private:
    FlightsInfo information;
    FlightsStats statistics;
    FlightsSearcher searcher;
public:
    FlightsManager();
    FlightsManager(FlightsManager& another);
    ~FlightsManager();

    void readFile();
    void addFlight();
    void removeFlight(int& flight_index);

    void informationPrint();
    void statisticsPrint();
    void searchPrint();

    void makeStats(bool by_destination);
    void searchPlane(char& symbol);

    void sortInformation(char& choice);
    void sortStatistics(char& choice);
    void sortSearch(char& choice);

    void managerWrite(char& choice);

    FlightsManager& operator=(const FlightsManager& another);
    friend ostream& operator<<(ostream& os, const FlightsManager& mngr);
};

#endif //FLIGHTSMANAGE_H
