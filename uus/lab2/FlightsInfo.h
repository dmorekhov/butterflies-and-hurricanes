#ifndef FLIGHTSINFO_H
#define FLIGHTSINFO_H

#include <string>
#include <iostream>

using namespace std;

struct Date {
    int year;
    short month;
    short day;
    short hour;
    short minute;
};

struct Departure {
    string plane;
    string destination;
    double cost;
    Date date;
};

class FlightsInfo {
private:
    Departure* flights_info;
    int flights;
public:
    FlightsInfo();
    FlightsInfo(const FlightsInfo& another_data);
    ~FlightsInfo();

    void addFlight(const Departure& flight);
    void deleteFlight(int& flight_number);

    void resize(int new_length);

    void printFlights();

    void inputFile();
    void outputFile();

    void sortName();
    void sortYear();
    void sortDate();
    void sortCost();
};

bool compareNamesUtil(Departure& flight1, Departure& flight2);
bool compareYearsUtil(Departure& flight1, Departure& flight2);
bool compareDatesUtil(Departure& flight1, Departure& flight2);
bool compareCostsUtil(Departure& flight1, Departure& flight2);


#endif //FLIGHTSINFO_H
