#ifndef FLIGHTSINFO_H
#define FLIGHTSINFO_H

#include <string>
#include <iostream>

using namespace std;

struct Date {
    int year;
    short day;
    short month;
    short hour;
    short minute;
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        if (day != other.day) return day < other.day;
        if (hour != other.hour) return hour < other.hour;
        return minute < other.minute;
    }
};

struct Departure {
    string plane;
    string destination;
    double cost;
    Date date;
    bool operator<(const Departure& other) const {
        return date < other.date;
    }
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

    void inputFile();
    void outputFile();

    void sortName();
    void sortYear();
    void sortDate();
    void sortCost();

    friend ostream& operator<<(ostream& out, const FlightsInfo& info);
    FlightsInfo& operator=(const FlightsInfo& another_data);
};

bool compareNamesUtil(Departure& flight1, Departure& flight2);
bool compareYearsUtil(Departure& flight1, Departure& flight2);
bool compareDatesUtil(Departure& flight1, Departure& flight2);
bool compareCostsUtil(Departure& flight1, Departure& flight2);


// bool operator>(const Date& first, const Date& second);
// bool operator<=(const Date& first, const Date& second);
// bool operator>=(const Date& first, const Date& second);
// bool operator==(const Date& first, const Date& second);
// bool operator!=(const Date& first, const Date& second);

ostream& operator<<(ostream& os, const Date& date);
ostream& operator<<(ostream& os, const Departure& flight);


#endif //FLIGHTSINFO_H
