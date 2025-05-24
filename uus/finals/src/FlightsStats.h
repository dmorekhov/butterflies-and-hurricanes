#ifndef FLIGHTSLIST_H
#define FLIGHTSLIST_H

#include <iomanip>
#include <string>
#include <iostream>
#include "FlightsInfo.h"

using namespace std;

struct FlightStat {
    string category;
    int count;
    double total_cost;
    friend ostream& operator<<(ostream& os, const FlightStat& flight) {
        const int category_width = 20;
        const int count_width = 10;
        const int cost_width = 15;
        os << "| " << left << setw(category_width) << flight.category << " | "
       << right << setw(count_width) << flight.count << " | "
       << setw(cost_width) << fixed << setprecision(2) << flight.total_cost / flight.count  <<" |" << endl;
        return os;
    }
};

class FlightsStats : public FlightsInfo {
private:
    FlightStat* stats;
    int size;
public:
    FlightsStats();
    FlightsStats(const FlightsStats& another);
    ~FlightsStats();

    void write();
    void print();

    void sortStatistics(const char& choice);
    void sortPrices();
    void sortCategories();

    FlightsStats& operator=(const FlightsStats& another);

    void getStats(bool by_destination);

    friend ostream& operator<<(ostream& os, const FlightsStats& flight_stats);
};

bool compareAveragePrices(const FlightStat& first, const FlightStat& second);
bool compareCategory(const FlightStat& first, const FlightStat& second);

#endif //FLIGHTSLIST_H
