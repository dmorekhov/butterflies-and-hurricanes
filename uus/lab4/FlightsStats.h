#ifndef FLIGHTSLIST_H
#define FLIGHTSLIST_H

#include "FlightStruct.h"

class FlightsInfo;

struct FlightStat {
    string category;
    int count;
    double total_cost;

    friend ostream& operator<<(ostream& os, const FlightStat& flight_stat) {
        double avg_cost = flight_stat.count > 0 ? flight_stat.total_cost / flight_stat.count : 0;
        os << flight_stat.category << ": " << flight_stat.count << " flights";
        if (flight_stat.count > 0) {
            os << " (average cost " << fixed << setprecision(2) << avg_cost << ")";
        }
        return os;
    }
};

class FlightsStats {
private:
    FlightStat* stats;
    int size;
public:
    FlightsStats();
    FlightsStats(const FlightsStats& another);
    ~FlightsStats();

    void WriteFile();

    void sortPrices();
    void sortCategories();

    FlightsStats& operator=(const FlightsStats& another);

    friend void getStats(const FlightsInfo& info, FlightsStats& result, bool by_destination);

    friend ostream& operator<<(ostream& os, const FlightsStats& flight_stats);
};

bool compareAveragePrices(const FlightStat& first, const FlightStat& second);
bool compareCategory(const FlightStat& first, const FlightStat& second);

#endif //FLIGHTSLIST_H
