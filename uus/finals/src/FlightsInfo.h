#ifndef FLIGHTSINFO_H
#define FLIGHTSINFO_H

#include <iostream>
#include "FlightStruct.h"

using namespace std;

class FlightsInfo {
protected:
    Departure* flights_info;
    int flights;
public:
    FlightsInfo();
    FlightsInfo(const FlightsInfo& another_data);
    ~FlightsInfo();

    void addFlight();
    void deleteFlight(const int& flight_number);

    void resize(const int new_length);

    void inputFile();
    void write();
    void print();

    void sortInfo(const char& choice);

    void sortName();
    void sortYear();
    void sortDate();
    void sortCost();

    friend ostream& operator<<(ostream& out, const FlightsInfo& info);
    friend istream& operator>>(istream& is, FlightsInfo& info);
    FlightsInfo& operator=(const FlightsInfo& another_data);
};

bool compareNamesUtil(Departure& flight1, Departure& flight2);
bool compareYearsUtil(Departure& flight1, Departure& flight2);
bool compareCostUtil(Departure& flight1, Departure& flight2);

#endif //FLIGHTSINFO_H
