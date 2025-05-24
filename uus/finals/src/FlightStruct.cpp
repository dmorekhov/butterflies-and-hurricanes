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

ostream& operator<<(ostream& out, const Departure& current_flight) {
    const int name_width = 18;
    const int dest_width = 18;
    const int price_width = 10;
    const int date_width = 16;
    out << "| " << left << setw(name_width) << current_flight.plane << " | "
           << setw(dest_width) << current_flight.destination << " | "
           << right << setw(price_width) << fixed << setprecision(2) << current_flight.cost << " | "
           << left << setw(date_width) << current_flight.date << " |" << endl;
    return out;
}