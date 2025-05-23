#ifndef FLIGHTSINFO_H
#define FLIGHTSINFO_H

#include <iostream>

#include "FlightStruct.h"

class FlightsStats;
class FlightsSearcher;

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
    friend void findFlightsByDestination(const FlightsInfo& info, FlightsSearcher& result, const string& dest);
    friend void findFlightsByPlane(const FlightsInfo& info, FlightsSearcher& result, const string& plane);
    friend void findFlightByCostRange(const FlightsInfo& info, FlightsSearcher& result, double min, double max);
};

bool compareNamesUtil(Departure& flight1, Departure& flight2);
bool compareYearsUtil(Departure& flight1, Departure& flight2);
bool compareCostUtil(Departure& flight1, Departure& flight2);

#endif //FLIGHTSINFO_H
