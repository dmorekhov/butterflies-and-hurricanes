#ifndef FLIGHTSSEARCHER_H
#define FLIGHTSSEARCHER_H

#include "FlightStruct.h"

class FlightsInfo;

class FlightsSearcher {
private:
    Departure* results;
    int count;
public:

    FlightsSearcher();
    FlightsSearcher(const FlightsSearcher& another);
    ~FlightsSearcher();

    void clear();

    void add(const Departure& departure);
    void fileWrite();

    void sortByDate();
    void sortByCost();
    void sortByDestination();
    void sortByPlane();

    FlightsSearcher& operator=(const FlightsSearcher& another);
    friend ostream& operator<<(ostream& os, const FlightsSearcher& result);

    friend void findFlightsByDestination(const FlightsInfo& info, FlightsSearcher& result, const string& dest);
    friend void findFlightsByPlane(const FlightsInfo& info, FlightsSearcher& result, const string& plane);
    friend void findFlightByCostRange(const FlightsInfo& info, FlightsSearcher& result, double min, double max);
};

bool compCostUtil(const Departure& a, const Departure& b);
bool compDestinationUtil(const Departure& a, const Departure& b);
bool compPlaneUtil(const Departure& a, const Departure& b);

#endif //FLIGHTSSEARCHER_H
