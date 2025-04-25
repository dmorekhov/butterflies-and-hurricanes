#ifndef STUDENTINFO_H
#define STUDENTINFO_H
#define MAX_FLIGHTS 100

#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

struct Date {
    short year;
    short month;
    short day;
    short hour;
    short minute;
};

struct Departure {
    string plane;
    string arrival_place;
    double cost;
    Date departure_date;
};

class FlightsInfo {
private:
    int amount_of_flights = 0;
    Departure flights[MAX_FLIGHTS];

public:
    FlightsInfo();
    ~FlightsInfo();

    void addFlight(Departure& flight);
    void deleteFlight(int& index);
    void output();
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

#endif //STUDENTINFO_H
