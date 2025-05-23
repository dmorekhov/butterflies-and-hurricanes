#ifndef FLIGHTSSEARCHER_H
#define FLIGHTSSEARCHER_H

#include "FlightsStats.h"
#include "FlightStruct.h"

class FlightsSearcher : public FlightsStats {
private:
    Departure* results;
    int count;
public:

    FlightsSearcher();
    FlightsSearcher(const FlightsSearcher& another);
    ~FlightsSearcher();

    void clear();

    void add(const Departure& departure);
    void write();

    void sortByDate();
    void sortByCost();
    void sortByDestination();
    void sortByPlane();

    void find(char& choice);
    void print();

    FlightsSearcher& operator=(const FlightsSearcher& another);
    friend ostream& operator<<(ostream& os, const FlightsSearcher& result);

    void findFlightsByDestination(const string& dest);
    void findFlightsByPlane(const string& plane);
    void findFlightByCostRange(double min, double max);
};

bool compCostUtil(const Departure& a, const Departure& b);
bool compDestinationUtil(const Departure& a, const Departure& b);
bool compPlaneUtil(const Departure& a, const Departure& b);

#endif //FLIGHTSSEARCHER_H
