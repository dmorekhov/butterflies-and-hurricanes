#ifndef FLIGHTSTRUCT_H
#define FLIGHTSTRUCT_H

#include <iomanip>

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

ostream& operator<<(ostream& os, const Date& date);

ostream& operator<<(ostream& os, const Departure& flight);

istream& operator>>(istream& is, Departure& s);

#endif //FLIGHTSTRUCT_H
