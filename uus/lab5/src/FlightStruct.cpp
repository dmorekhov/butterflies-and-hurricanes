#include "FlightStruct.h"

ostream& operator<<(ostream& os, const Date& date) {
    os << setfill('0');
    os << setw(4) << date.year << '-'
        << string((date.day / 10) == 0, '0')  << date.day << '-'
        << string((date.month / 10) == 0, '0') << date.month << ' '
        << string((date.hour / 10) == 0, '0') << date.hour << ':'
        << string((date.minute / 10) == 0, '0') << date.minute;
    os << setfill(' ');
    return os;
}

ostream& operator<<(ostream& os, const Departure& flight) {
    os << "Plane: " << setw(10) << left << flight.plane
        << "| Destination: " << setw(15) << left << flight.destination
        << " | Cost: " << flight.cost
        << " | Date: " << flight.date;
    return os;
}