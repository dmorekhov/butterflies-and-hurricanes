#ifndef FLIGHTSINFO_H
#define FLIGHTSINFO_H

#include <iostream>
#include "FlightStruct.h"

class FlightsStats;

using namespace std;

class FlightsInfo {
private:
    Departure* flights_info;
    int flights;
public:
    FlightsInfo();
    FlightsInfo(const FlightsInfo& another_data);
    ~FlightsInfo();

    void addFlight(Departure& flight);
    void deleteFlight(int& flight_number);

    void resize(int new_length);

    void inputFile();
    void outputFile();

    void sortName();
    void sortYear();
    void sortDate();
    void sortCost();

    friend ostream& operator<<(ostream& out, const FlightsInfo& info);
    FlightsInfo& operator=(const FlightsInfo& another_data);

    friend void getStats(const FlightsInfo& info, FlightsStats& result, bool by_destination);
};

bool compareNamesUtil(Departure& flight1, Departure& flight2);
bool compareYearsUtil(Departure& flight1, Departure& flight2);
bool compareCostUtil(Departure& flight1, Departure& flight2);

#endif //FLIGHTSINFO_H
