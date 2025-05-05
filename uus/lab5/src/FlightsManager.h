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
    void writeFile();
    void addFlight();
    void removeFlight();

    void informationPrint();

    FlightsManager& operator=(const FlightsManager& another);
    friend ostream& operator<<(ostream& os, const FlightsManager& mngr);
};

#endif //FLIGHTSMANAGE_H
